#include <stdio.h>

int mmc(int a, int b) // implementação recursiva.
{
    if (a%b == 0)
    {
        return b;
    }
    
    int r = a%b;

    return mmc(b, r);
}

int main(int argc, char const *argv[])
{
    int x, y;

    while (scanf("%d %d", &x, &y) != EOF)
    {
        if (x > 0 && y > 0)
        {
            printf("%d %d %d \n", x, y, mmc(x,y));
        }
        
    }
    
    
    return 0;
}
