#include <stdio.h>
int main()
{
    int number, isNegative = 0, result = 0;
    scanf("%d", &number);
    if (number < 0)
    {
        number = -number;
        isNegative = 1;
    }
    while (number > 0)
    {
        result = result * 10 + number % 10;
        number /= 10;
    }
    if (isNegative)
        result = -result;
    printf("%d", result);
    return 0;
}
