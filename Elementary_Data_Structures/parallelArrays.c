#include <stdio.h>

// implementação do livro de uma linked-list usando arrays paralelos.
#define MAX 30

int head, a, x;
int key[MAX + 2], next[MAX + 2];

void initializeList()
{
    head = 0, a = 1, x = 2;
    next[head] = a;
    next[a] = a;
}

void deleteAfter(int t)
{
    next[t] = next[next[t]];
}    

int insertAfter(int element, int aft)
{
    key[x] = element;
    next[x] = next[aft];
    next[aft] = x;
    return x++;
}

int main(int argc, char const *argv[])
{
    initializeList();

    return 0;
}
