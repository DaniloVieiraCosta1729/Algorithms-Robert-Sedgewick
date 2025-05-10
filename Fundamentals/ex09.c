//find the largest pair of numbers representable as integers in your C system whose greatest common divisor is 1.
//Vou entender como maior par o par cujo um dos números é o maior inteiro representável e o segundo é o maior número representável que é primo com o primeiro. 
//Outra interpretação para maior par é o par cuja a soma é a maior possível. (se olharmos para o par como um vetor em R^2, podemos pensar que o maior par é aquele que tem o maior módulo).
#include <stdio.h>
#include <limits.h>

#define MAIOR INT_MAX;

int mdcEx09(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    
    return mdcEx09(b, a%b);
}

int main(int argc, char const *argv[])
{
    int m = MAIOR
    int n = m-1;

    int mdc = mdcEx09(m, n);
    
    while (mdc != 1)
    {
        n--;
        mdc = mdcEx09(m, n);
    }

    printf("O maior par de primos entre si nesse sistema eh: %d, %d", m, n);
    
    return 0;
}

