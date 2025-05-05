#include <stdio.h>
#include "VersaoDoLivro.h"

int mmc(int a, int b) // implementação recursiva.
{
    if (a%b == 0)
    {
        return b;
    }
    
    int r = a%b;

    return mmc(b, r);
}

void reduz(int a, int b)
{
    int maximoDivisor = mmc(a,b);
    printf("%d / %d \n", a/maximoDivisor, b/maximoDivisor);
}

void reduzSedgewick(int a, int b)
{
    int maximoDivisor = mmcSedgewick(a,b);
    printf("%d / %d \n", a/maximoDivisor, b/maximoDivisor);
}

int main()
{
    // Escrever um programa que reduza frações.

    printf("Para 31 e 7\n");
    reduz(31, 7);
    printf("\nPara 25 e 15\n");
    reduz(25, 15);

    printf("\n\n\n\nPara 31 e 7\n");
    reduzSedgewick(31, 7);
    printf("\nPara 25 e 15\n");
    reduzSedgewick(25, 15);

    return 0;
}