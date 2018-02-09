#include <stdio.h>
int main()
{
    int x;
    long n, result = 0;
    scanf("%d %ld", &x, &n);
    for (int i = x; i <= 5; i++)
        result += 250;
    n = n - (7 - x + 1);
    result += n / 7 * 1250;
    for (int i = 1; i <= 5 && i <= n % 7; i++)
        result += 250;
    printf("%ld", result);
    return 0;
}
