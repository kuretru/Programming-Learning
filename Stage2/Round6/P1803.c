#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int start;
    int end;
} match;
int qcmp(const void *a, const void *b)
{
    match *x = (match *)a;
    match *y = (match *)b;
    if (x->end == y->end)
        return x->start - y->start;
    return x->end - y->end;
}
int main()
{
    int n, count = 0, end = 0;
    scanf("%d", &n);
    match *data = (match *)malloc(n * sizeof(match));
    for (int i = 0; i < n; i++)
        scanf("%d %d", &data[i].start, &data[i].end);
    qsort(data, n, sizeof(match), qcmp);
    for (int i = 0; i < n; i++)
    {
        if (data[i].start >= end)
        {
            end = data[i].end;
            count++;
        }
    }
    printf("%d", count);
    free(data);
    return 0;
}
