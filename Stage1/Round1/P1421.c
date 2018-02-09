#include <stdio.h>
int main()
{
    int a, b;
    float c, d;
    scanf("%d %d", &a, &b);
    c = a + b * 0.1;
    d = c / 1.9;
    printf("%d", (int)d);
    return 0;
}
