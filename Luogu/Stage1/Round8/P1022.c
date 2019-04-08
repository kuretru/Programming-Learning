#include <stdio.h>
#include <string.h>
int main()
{
    char symbol, text[100];
    int x[2] = {0}, number[2] = {0}, index = 0;
    int tmp = 0, isNegative = 0, isSymbol = 0;
    gets(text);
    int length = strlen(text);
    for (int i = 0; i <= length; i++)
    {
        if (text[i] >= '0' && text[i] <= '9')
            tmp = tmp * 10 + text[i] - '0';
        else
        {
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                symbol = text[i];
                isSymbol = 1;
            }
            if (isNegative)
            {
                tmp = -tmp;
                isNegative = 0;
            }
            if (isSymbol)
            {
                x[index] += tmp;
                isSymbol = 0;
            }
            else
            {
                number[index] += tmp;
            }
            if (text[i] == '=')
            {
                index++;
            }
            else if (text[i] == '-')
            {
                isNegative = 1;
            }
            tmp = 0;
        }
    }
    printf("%c=%.3lf", symbol, (number[1] - number[0]) * 1.0 / (x[0] - x[1]));
    return 0;
}
