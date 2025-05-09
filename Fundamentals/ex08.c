//Write a program to compute the greatest common divisor of three integers u, v, and w.
#include <stdio.h>

int mdc(int a, int b) // implementação recursiva.
{
    if (a%b == 0)
    {
        return b;
    }
    
    return mdc(b, a%b);
}

int mdcXYZ(int x, int y, int z)
{
    return mdc(mdc(x, y), z);
}

int main(int argc, char const *argv[])
{
    int x;
    int y;
    int z;
    printf("Funcao mdc(x,y,z):");
    scanf("%d %d %d", &x, &y, &z);

    int mdc = mdcXYZ(x,y,z);

    printf("%d", mdc);
    
    return 0;
}
