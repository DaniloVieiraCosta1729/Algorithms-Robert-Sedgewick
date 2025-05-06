// Implement a procedure to reduce a given fraction to lowest terms, using a struct fraction {int numerator; int denominator;}.
#include <stdio.h>

int mmc(int x, int y)
{
    if (x%y == 0)
    {
        return y;
    }

    return mmc(y,x%y);
}

typedef struct
{
    int numerator;
    int denominator;
} Fraction;

Fraction reduceFraction(int x, int y)
{
    Fraction f;
    f.numerator = x / mmc(x, y);
    f.denominator = y / mmc(x, y);
    return f;
}

void showFraction(Fraction f)
{
    printf("Numerator: %d \nDenominator: %d\n", f.numerator, f.denominator);
}

int main(int argc, char const *argv[])
{
    Fraction f25_15 = reduceFraction(25,15);

    showFraction(f25_15);

    return 0;
}
