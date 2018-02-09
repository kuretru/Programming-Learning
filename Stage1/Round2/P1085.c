#include <stdio.h>
int main()
{
    int a, b, result = 0;
    for (int i = 1; i <= 7; i++)
    {
        scanf("%d %d", &a, &b);
        if (a + b > 8 && result == 0)
            result = i;
    }
    printf("%d", result);
    return 0;
}
