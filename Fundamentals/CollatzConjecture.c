// A conjectura de Collatz enuncia que a função f, dos inteiros positivos nos inteiros positivos, definida por f(n) = n/2, se n é par e 3n+1, se n é ímpar tem a seguinte propriedade:
// Para todo elemento do domínio, a aplicação sucesiva de f, eventualmente resulta em 1. Por exemplo, se n é 1 temos
/*
f(1) = 3*1+1 = 4
f(f(1)) = f(4) = 4/2 = 2
f(f(f(1))) = f(2) = 1
*/

#include <stdio.h>

int collatz(int n)
{
    if (n%2 == 0)
    {
        return n/2;
    }
    
    return 3 * n + 1;
}

int cicloCollatz(int n)
{
    if (n == 1)
    {
        return 0;
    }

    printf("\n%d", collatz(n));

    return cicloCollatz(collatz(n));
    // Rezemos para que não estoure a stack...    
}

void stepCollatz()
{
    int n;
    int iterador = 1;

    printf("Escolha uma entrada: ");
    scanf("%d", &n);

    n = collatz(n);

    printf("\nresultado: %d", n);

    while (iterador != 0)
    {
        printf("\nIterar? S=1 / N=0: ");
        scanf("%d", &iterador);

        if (iterador != 0)
        {
            iterador = 1;
            n = collatz(n);
            printf("\nf = %d", n);
            continue;
        }

        break;
    }
}

int main(int argc, char const *argv[])
{
    //stepCollatz();

    int n;

    printf("Escolha uma entrada: ");
    scanf("%d", &n);

    cicloCollatz(n);
    
    return 0;
}
