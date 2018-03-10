#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int index;
    int value;
} pair;
int qcmp(const void *a, const void *b)
{
    pair *x = (pair *)a;
    pair *y = (pair *)b;
    if (x->value == y->value)
        return x->index - y->index;
    return x->value - y->value;
}
int main()
{
    int n;
    double sum = 0;
    scanf("%d", &n);
    pair *data = (pair *)malloc(n * sizeof(pair));
    for (int i = 0; i < n; i++)
    {
        data[i].index = i + 1;
        scanf("%d", &data[i].value);
    }
    qsort(data, n, sizeof(pair), qcmp);
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", data[i].index, i != n - 1 ? ' ' : '\n');
        sum += data[i].value * (n - i - 1);
    }
    printf("%.2f", sum / n);
    free(data);
    return 0;
}
