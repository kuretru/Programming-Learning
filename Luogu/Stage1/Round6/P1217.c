#include <math.h>
#include <stdio.h>
int root(int n)
{
    return (int)sqrt((float)n);
}
int prime(int n)
{
    int i, bound;
    if (n % 2 == 0)
        return (n == 2);
    if (n % 3 == 0)
        return (n == 3);
    if (n % 5 == 0)
        return (n == 5);
    bound = root(n);
    for (i = 7; i <= bound; i = i + 2)
        if (n % i == 0)
            return 0;
    return 1;
}
int reverse(int number)
{
    int n = 0;
    int m = number;
    while (m != 0)
    {
        n = n * 10 + m % 10;
        m = m / 10;
    }
    if (n == number)
        return 1;
    else
        return 0;
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= 9999999 && i <= b; i++)
    {
        if (reverse(i) && prime(i))
            printf("%d\n", i);
    }
    return 0;
}
