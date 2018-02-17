#include <stdio.h>
int main()
{
    int n, pow;
    scanf("%d", &n);
    for (int i = n; i >= 0; i--)
    {
        scanf("%d", &pow);
        if (pow != 0)
        {
            if (pow > 0 && i != n)
                printf("+");
            if ((pow != 1 && pow != -1 )|| i == 0)
                printf("%d", pow);
            else if (pow == -1)
                printf("-");
            if (pow != 0 && i > 0)
                printf("x");
            if (i > 1 )
                printf("^%d", i);
        }
    }
    return 0;
}
