#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int enable;
    int value;
} pair;
int qcmp(const void *a, const void *b)
{
    pair *x = (pair *)a;
    pair *y = (pair *)b;
    return x->value - y->value;
}
int main()
{
    int w, n, count = 0;
    scanf("%d %d", &w, &n);
    pair *data = (pair *)malloc(n * sizeof(pair));
    for (int i = 0; i < n; i++)
    {
        data[i].enable = 1;
        scanf("%d", &data[i].value);
    }
    qsort(data, n, sizeof(pair), qcmp);
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (data[i].value + data[j].value <= w)
            i++;
        count++;
        j--;
    }
    printf("%d", count);
    free(data);
    return 0;
}
