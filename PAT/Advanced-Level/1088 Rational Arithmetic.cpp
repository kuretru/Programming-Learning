#include <iostream>

const int plus = 0, minus = 1, multiply = 2, divide = 3;
const char *operators = "+-*/";

long gcd(long x, long y);

struct rational
{
    long numerator = 0;
    long denominator = 0;
    int symbol = 0;

    rational(long numerator, long denominator)
    {
        this->symbol = numerator > 0 ? 1 : -1;
        long tmp = std::abs(gcd(numerator, denominator));
        this->numerator = this->symbol * std::abs(numerator / tmp);
        this->denominator = std::abs(denominator / tmp);
    }
};

rational input();
void output(rational number);
void print(int type, rational x, rational y, rational z);

int main()
{
    rational x = input();
    rational y = input();
    print(plus, x, y, rational(x.numerator * y.denominator + y.numerator * x.denominator, x.denominator * y.denominator));
    print(minus, x, y, rational(x.numerator * y.denominator - y.numerator * x.denominator, x.denominator * y.denominator));
    print(multiply, x, y, rational(x.numerator * y.numerator, x.denominator * y.denominator));
    print(divide, x, y, rational(x.symbol * y.symbol * std::abs(x.numerator * y.denominator), x.denominator * y.numerator));
    return 0;
}

long gcd(long x, long y)
{
    return y == 0 ? x : gcd(y, x % y);
}

rational input()
{
    long x = 0, y = 0;
    scanf("%ld/%ld", &x, &y);
    return rational(x, y);
}

void output(rational number)
{
    if (number.numerator == 0)
    {
        printf("0");
        return;
    }
    number.numerator = std::abs(number.numerator);

    printf("%s", number.symbol == -1 ? "(-" : "");
    if (number.numerator >= number.denominator)
    {
        long integer = number.numerator / number.denominator;
        number.numerator %= number.denominator;
        printf("%ld%s", integer, number.numerator > 0 ? " " : "");
    }
    if (number.numerator > 0)
        printf("%ld/%ld", number.numerator, number.denominator);
    printf("%s", number.symbol == -1 ? ")" : "");
}

void print(int type, rational x, rational y, rational z)
{
    output(x);
    printf(" %c ", operators[type]);
    output(y);
    printf(" = ");
    if (type == divide && y.numerator == 0)
        printf("Inf");
    else
        output(z);
    printf("\n");
}
