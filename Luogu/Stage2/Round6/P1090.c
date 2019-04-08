#include <stdio.h>
#include <stdlib.h>
int data[2][10000];
int qcmp(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    return x - y;
}
int main()
{
    int count, sum = 0, used = 0;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
        scanf("%d", &data[used][i]);
    qsort(data[0], count, sizeof(int), qcmp);
    while (count > 1)
    {
        int min = data[used][0] + data[used][1];
        int index = 0, found = 0;
        sum += min;
        for (int i = 2; i < count; i++)
        {
            if (min <= data[used][i] && !found)
            {
                data[!used][index++] = min;
                found = 1;
            }
            data[!used][index++] = data[used][i];
        }
        if (min > data[used][--count])
            data[!used][index++] = min;
        used = !used;
    }
    printf("%d", sum);
    return 0;
}
