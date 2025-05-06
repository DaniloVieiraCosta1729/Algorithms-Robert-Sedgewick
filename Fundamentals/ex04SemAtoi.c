#include <stdio.h>
#include "ex04SemAtoi.h"

int power(int b, int e)
{
    if (e == 0)
    {
        return 1;
    }

    return b * power(b, e - 1); // tem memória, éh pra usar mesmo.
}

int convert()
{
    // '0' = 48, ..., '9' = 57
    // BLANK = 32.

    char c;
    char texto[8];
    int i = 0;
    int exp = 0;
    int k = 7;
    int result = 0;

    while ((c = getchar()) != 32)
    {
        texto[i] = c;
        i++;
    }

    for (i > -1; i--;)
    {
        result += (texto[i]-48) * power(10, exp);
        exp++;
    }
    

    return result;
}