/*
write a function int convert() that reads a decimal number one character (digit) at a time, terminated by a blank, and returns the value of that number.
*/

// Em stdlib.h existe uma função chamada atoi() que transforma string em int. Vamos fazer duas soluções, uma usando atoi e outra criando uma função que faça isso.

#include <stdio.h>
#include <stdlib.h>
#include "ex04SemAtoi.h"

int convertAtoi()
{ 
    char texto[8];
    char c;
    int i = 1;

    while (((c = getchar()) != ' ') && i < 9)
    {
        texto[i-1] = c;
        i++;
    }

    return atoi(texto);
}

int main(int argc, char const *argv[])
{
    //int x = convertAtoi();
    //printf("%d \n", x);

    int x = convert(); // sem a função atoi da stdlib.h

    printf("%d \n", x);

    return 0;
}
