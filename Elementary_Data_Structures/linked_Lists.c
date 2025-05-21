#include <stdlib.h>

struct node 
{
    int value;
    struct node *next;
};

struct node *head, *tail, *t;

void initializeList()
{
    // vamos criar espaço dinamicamente na heap, para permitir que a lista funcione normalmente e cresça.
    head = (struct node *) malloc(sizeof(struct node)); // deve ser uns 8 bytes, ou um pouco mais, porque cada nó só tem um ponteiro e um inteiro.
    tail = (struct node *) malloc(sizeof(struct node));

    head->next = tail;
    tail->next = tail;
};

struct node * insertNext(int v, struct node *t)
{
    struct node *x;
    x = (struct node *) malloc(sizeof(struct node));

    x->value = v;
    x->next = t->next;
    t->next = x;

    return x;
}

void deleteNext(struct node *t)
{
    t->next = t->next->next;
}

int main(int argc, char const *argv[])
{

    return 0;
}
