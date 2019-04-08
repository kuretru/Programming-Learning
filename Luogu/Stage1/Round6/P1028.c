#include <stdio.h>
int main()
{
    int n, table[1001] = {1, 1};
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
            table[i] = table[i - 1] + table[i / 2];
        else
            table[i] = table[i - 1];
    }
    printf("%d", table[n]);
    return 0;
}
