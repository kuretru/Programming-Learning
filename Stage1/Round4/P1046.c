#include <stdio.h>
int main()
{
    int hand, data[10], count = 0;
    for (int i = 0; i < 10; i++)
        scanf("%d", &data[i]);
    scanf("%d", &hand);
    for (int i = 0; i < 10; i++)
    {
        if (hand + 30 >= data[i])
            count++;
    }
    printf("%d", count);
    return 0;
}
