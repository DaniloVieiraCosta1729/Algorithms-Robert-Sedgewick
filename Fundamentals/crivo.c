// Aplicação comum de array.
#include <stdio.h>

#define MAX 1000

int main(int argc, char const *argv[])
{
    int i, j, num[MAX+1];
    num[1] = 0;

    for (i = 2; i <= MAX; i++)
    {
        num[i] = 1;
    }
    
    for (i = 2; i <= MAX/2; i++)
    {
        for (j = 2; j <= MAX/i; j++) // perceba que não tem erro, porque i*j é, no máximo, N.
        {
            num[i*j] = 0;
        }
        
    }

    for (i = 1; i <= MAX; i++)
    {
        if (num[i])
        {
            printf("%d \n", i);
        }
        
    }    

    return 0;
}
