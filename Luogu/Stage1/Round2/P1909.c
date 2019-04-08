#include <stdio.h>
int main()
{
    int n, result = 2000000000;
    int count, price, tmp;
    scanf("%d", &n);
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d", &count, &price);
        tmp = (n + (count - 1)) / count;
        tmp *= price;
        if (tmp < result)
            result = tmp;
    }
    printf("%d", result);
    return 0;
}
