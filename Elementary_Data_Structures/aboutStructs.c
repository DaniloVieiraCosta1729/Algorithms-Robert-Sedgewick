#include <stdio.h>
#include <stddef.h>

// Nesse arquivo, vou fazer algumas experiências com structs e testas as informações que obtive com uma pesquisa sobre essa estrutura de dados.

int main(int argc, char const *argv[])
{
    struct badPosition
    {
        int x; // 4 bytes
        void * ptr; // 8 bytes
        int y; // 4 bytes
    }; // como o compilador resolve uma struct? 

    /*
    Olhando os campos dela, parece que o compilador vai precisar usar 16 bytes para guardá-la, mas, na vdd, a forma como a gente dispoe os campos impacta muito no tamnho que as instancias de badPosition vão ter.
    */

    printf("Tamanho de badPosition: %zu\n", sizeof(struct badPosition)); // mostra 24 bytes e não 16. 

    /*
    Isso acontece porque o compilador vai dispôr os elementos da struct em sequência e de modo que eles fiquem adjacentes dois a dois, porém, em uma arquitetura de 64 bits, não é possível colocar um ponteiro imediatamente após um inteiro, pois um ponteiro ocupa 8 bytes (64 bits) e um inteiro ocupa 32 bits. Ou seja, não existe espaço o suficiente para colocar um ponteiro entre o final de x e o começo da próxima "word".
    
    Como resultado, o compilador preenche esse espaço com 4 bytes. Esses bytes não ficaram disponíveis para o sistema, a gente até consegue acessar com ponteiros, por exemplo, char * p = (char *)&estrutura; (p + 4) é o começo do padding (preenchimento).

    O compilador não reorganizar o layout da struct, porque isso afetaria o resultado esperado pelo programador ao usar ponteiros para acessar os campos da struct, então ele mantem ela exatamente como o programador fez. (Tem outros motivos, mas esse é o que eu entendi melhor e fez muito sentido pra mim.)
    */

    struct goodPosition
    {
        void * ptr;
        int x;
        int y;
    };

    printf("Tamanho de badPosition: %zu\n", sizeof(struct goodPosition)); // apenas 16 bytes.

    //  |####|____|########|####|____|     <- badPosition 
    //  |########|####|####|               <- goodPosition



    // Vamos explorar as structs usando pointers.
    
    struct badPosition bad = {1, &bad, 2};
    char * p = (char *)&bad;

    printf("Primeiro campo de bad: %d\n", *(int *)p);
    printf("Primeiro campo de bad: %d\n", *(int *)(p + 16)); // posição de bad + 16 bytes.

    // o offsetof(struct ... , w) mostra quantos bytes precisamos pular ao início de bad, para encontrar o campo w.
    printf("offset de x: %zu\n", offsetof(struct badPosition, x)); 
    printf("offset de y: %zu\n", offsetof(struct badPosition, y));
    printf("offset de ptr: %zu\n", offsetof(struct badPosition, ptr));
    
    return 0;
}
