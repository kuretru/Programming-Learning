#include <stdio.h>
int main()
{
    int i, key;
    double sum = 0;
    scanf("%d", &key);
    for (i = 1; i < 1000000000; i++)
    {
        sum += 1.0 / i;
        if (sum > key)
            break;
    }
    printf("%d", i);
    return 0;
}
