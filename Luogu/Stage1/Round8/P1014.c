#include <stdio.h>
int main()
{
    int i, n, sum = 0;
    scanf("%d", &n);
    for (i = 1; sum < n; i++)
        sum += i;
    i--;
    if (i % 2)
        printf("%d/%d", sum + 1 - n, i - sum + n);
    else
        printf("%d/%d", i - sum + n, sum + 1 - n);
    return 0;
}
