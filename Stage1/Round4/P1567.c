#include <stdio.h>
#include <stdlib.h>
int main()
{
    int count, *data;
    int tmp = 1, max = 0;
    scanf("%d", &count);
    data = malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++)
        scanf("%d", &data[i]);
    for (int i = 1; i < count; i++)
    {
        if (data[i] > data[i - 1])
            tmp++;
        else
        {
            if (tmp > max)
                max = tmp;
            tmp = 1;
        }
    }
    if (tmp > max)
        max = tmp;
    printf("%d", max);
    return 0;
}
