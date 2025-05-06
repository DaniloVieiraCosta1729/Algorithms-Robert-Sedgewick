#include <stdio.h>

typedef struct {
    int MAX;
    int TOP;
    char st[33];
} Stack33;

void push(char c, Stack33 *s)
{
    if (s->TOP >= s->MAX - 1)
    {
        printf("OVERFLOW.");
        return;
    }

    s->TOP++;
    s->st[s->TOP] = c;
}

char pop(Stack33 *s)
{
    if (s->TOP <= -1)
    {
        printf("UNDERFLOW.");
        return '\0';
    }

    char result = s->st[s->TOP];
    s->TOP--;

    return result;
}

char peek(Stack33 *s)
{
    if (s->TOP <= -1)
    {
        printf("EMPTY.");
        return '\0';
    }

    return s->st[s->TOP];
}

void binario(int n)
{
    Stack33 binario;
    binario.MAX = 33;
    binario.TOP = -1;

    while (n > 0)
    {
        push((char)((n % 2) + '0'), &binario);
        n = n / 2;
    }

    while (binario.TOP >= 0)
    {
        char c = pop(&binario);
        printf("%c", c);
    }
}

int main()
{
    binario(15);
    return 0;
}
