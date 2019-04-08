#include <stdio.h>
int main()
{
    int number, data[100], count = 100;
    for (int i = 0; i < 100; i++)
    {
        scanf("%d", &number);
        if (!number)
        {
            count = i;
            break;
        }
        data[i] = number;
    }
    for (int i = count - 1; i >= 0; i--)
    {
        printf("%d", data[i]);
        if (i != 0)
            printf(" ");
    }
    return 0;
}
