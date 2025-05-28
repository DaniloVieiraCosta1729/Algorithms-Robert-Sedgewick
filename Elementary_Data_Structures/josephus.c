/* Vou criar uma solução para o problema de Josephus usando algo que simula uma "circular linked-list".
 A razão para eu usar uma "simulação" é porque não me sinto seguro quanto ao gerenciamento de memória. 
 Por esse motivo, vou usar o que aprendi sobre pointers para criar algo inteiramente na stack. 
 EU SEI QUE O CÓDIGO ABAIXO É MUITO RUIM, mas eu quero testar pointers com esse problema e, depois disso, vou aprender a implementar essa estrutura de forma correta.*/

// O método vai ser por força bruta. Vamos simplesmente passar por todas as pessoas possíveis. 
// A versão que vai ser resolvida é tal que a contagem começa na própri pessoa que segura a espada, por exemplo, se o passo for 3, então a terceira pessoa é eliminada.

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "bookVersionJosephus.h"

int josephus(int quantity, int step){

    if ((quantity == 1) || (step < 0))
    {
        return 1;
    }
    

    struct node
    {
        struct node *next;
        int position;        
    };

    // Ao invés de usar um array, vou usar a função alloca para criar espaço na stack frame da função josephus para os nós da linked list. O motivo é (aplicar pointeiros, mesmo sem motivo).
    struct node * ptr = (struct node *)alloca(sizeof(struct node) * quantity);
    
    for (int i = 0; i < quantity; i++)
    {
        (ptr + i)->position = i + 1;
        (ptr + i)->next = &ptr[(i + 1) % quantity];
    }

    /*
    for (int i = 0; i < quantity; i++)
    {
        printf("-------- Node[%d] --------\nPosition: %d\nEndereco: %p\n\n", i, (ptr + i)->position, (ptr + i)->next);
    }
    */
    // Vamos resolver esse trem agora.

    struct node * temp;
    temp = ptr;

    for (int i = quantity; i > 1; i--)
    {
        for (int j = 0; j < step - 2; j++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        temp = temp->next;        
    }

    return temp->position;
    
}

int main(int argc, char const *argv[])
{    
    int a = 9;
    int b = 5;
    int meuResultado = josephus(a, b);
    int livroResultado = jose(a, b);
    
    printf("Minha solucao - Josephus(%d,%d) = %d\n", a, b, meuResultado);
    printf("Solucao livro - Josephus(%d,%d) = %d\n", a, b, livroResultado);

    return 0;
}
