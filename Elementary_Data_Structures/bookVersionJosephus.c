#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node * next;
    int place;
};

int jose(int n, int step)
{
    struct node * ptr, * aux;

    ptr = (struct node *)malloc(sizeof(* ptr));
    ptr->place = 1;
    aux = ptr;

    for (int i = 2; i <= n; i++)
    {
        ptr->next = (struct node *)malloc(sizeof(* ptr));
        ptr = ptr->next;
        ptr->place = i;   
    }

    ptr->next = aux;

    while (ptr != ptr->next)
    {
        for (int i = 1; i < step; i++)
        {
            ptr = ptr->next;
        }

        aux = ptr->next;
        ptr->next = ptr->next->next;
        free(aux);               
    }    

    return ptr->place;
}
