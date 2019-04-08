#include <stdio.h>
int main()
{
    int i;
    double power = 2, sum = 0, dest;
    scanf("%lf", &dest);
    for (i = 1; i < 1000000000; i++)
    {
        sum += power;
        if (sum >= dest)
            break;
        power *= 0.98;
    }
    printf("%d", i);
    return 0;
}
