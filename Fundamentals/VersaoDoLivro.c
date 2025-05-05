#include <stdio.h>
#include "VersaoDoLivro.h"

// No livro, Sedgewick não usa exatamente mdc(a,b)=mdc(b,r), com a=qb+r, 0 <= r < |b|.
// O que ele usa é algo similar, mas ao invés do resto r, ele usa a diferença a - b
// Ou seja, mdc(a,b) = mdc(b,a-b). A demonstração desse lema é igual a do lema que usamos, pois o "r" seria a-b, ao invés de a-qb, o que não afeta em nada o resultado.
// Outra diferença é que ele usou um while ao invés de chamar a função recursivamente. Só usei a recursão, porque não é algo tão velho pra mim ainda, então achei legal usar. Acho que a complexidade não mudou tanto, porque, embora a função precise ser chamada toda hora, a complexidade ainda é linear.

int mmcSedgewick(int x, int y)
{
    int temporario;
    while (x > 0)
    {
        if (x < y)
        {
            temporario = x;
            x = y;
            y = temporario;
        }

        x = x - y; // funciona como o resto
        
    }

    return y;
    
}