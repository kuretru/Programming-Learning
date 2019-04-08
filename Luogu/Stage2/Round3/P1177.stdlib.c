#include <stdio.h>
#include <stdlib.h>
int qcmp(const void *x, const void *y)
{
    return *(int *)x - *(int *)y;
}
int main()
{
    int count, *data;
    scanf("%d", &count);
    data = (int *)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++)
        scanf("%d", &data[i]);
    qsort(data, count, sizeof(int), qcmp);
    for (int i = 0; i < count; i++)
    {
        printf("%d", data[i]);
        if (i != count)
            printf(" ");
    }
    free(data);
    return 0;
}
