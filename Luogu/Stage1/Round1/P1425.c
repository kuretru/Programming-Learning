#include <stdio.h>
int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (d < b)
    {
        c--;
        d += 60;
    }
    printf("%d %d", c - a, d - b);
    return 0;
}
