#include <stdio.h>
int main()
{
    int data[10001] = {0};
    int max, groups, count = 0;
    scanf("%d %d", &max, &groups);
    while (groups--)
    {
        int low, height;
        scanf("%d %d", &low, &height);
        for (int i = low; i <= height; i++)
            data[i] = 1;
    }
    for (int i = 0; i <= max; i++)
        if (!data[i])
            count++;
    printf("%d", count);
    return 0;
}
