/* Vou criar uma solução para o problema de Josephus usando algo que simula uma "circular linked-list".
 A razão para eu usar uma "simulação" é porque não me sinto seguro quanto ao gerenciamento de memória. 
 Por esse motivo, vou usar o que aprendi sobre pointers para criar algo inteiramente na stack. 
 EU SEI QUE O CÓDIGO ABAIXO É MUITO RUIM, mas eu quero testar pointers com esse problema e, depois disso, vou aprender a implementar essa estrutura de forma correta.*/

// O método vai ser por força bruta. Vamos simplesmente passar por todas as pessoas possíveis. 

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void josephus(int quantity, int passo){

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

    for (int i = 0; i < quantity; i++)
    {
        printf("-------- Node[%d] --------\nPosition: %d\nEndereco: %p\n\n", i, (ptr + i)->position, (ptr + i)->next);
    }
    
    // Vamos resolver esse trem agora.
    
}

int main(int argc, char const *argv[])
{    
    josephus(10, 0);
    
    return 0;
}
