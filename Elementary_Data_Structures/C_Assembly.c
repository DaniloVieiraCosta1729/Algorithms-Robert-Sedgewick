#include <stdio.h>

extern int soma(int x, int y);

int main(int argc, char const *argv[])
{
    int a = 3;
    int b = 7;

    printf("%d + %d = %d\n", a, b, soma(a,b));
    return 0;
}
