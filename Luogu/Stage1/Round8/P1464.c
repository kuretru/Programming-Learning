#include <stdio.h>
typedef long long int64;
int cache[21][21][21];
int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    if (cache[a][b][c] == 0)
    {
        int number;
        if (a < b && b < c)
            number = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        else
            number = w(a - 1, b, c) + w(a - 1, b - 1, c) +
                     w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
        cache[a][b][c] = number;
    }
    return cache[a][b][c];
}
int main()
{
    int64 a, b, c;
    while (1)
    {
        scanf("%I64d %I64d %I64d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1)
            break;
        printf("w(%lld, %lld, %lld) = ", a, b, c);
        if (a > 20)
            a = 21;
        if (b > 20)
            b = 21;
        if (c > 20)
            c = 21;
        printf("%d\n", w(a, b, c));
    }
    return 0;
}
