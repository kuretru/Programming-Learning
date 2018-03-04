#include <stdio.h>
#include <stdlib.h>
struct person
{
    int D; //序号
    int W; //权重
} list[20000];
int cmp(const void *a, const void *b)
{
    struct person *x = (struct person *)a;
    struct person *y = (struct person *)b;
    if (y->W == x->W)
        return x->D - y->D;
    return y->W - x->W;
}
int main()
{
    int n, k, E[10];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < 10; i++)
        scanf("%d", &E[i]);
    for (int i = 0; i < n; i++)
    {
        list[i].D = i + 1;
        scanf("%d", &list[i].W);
    }
    qsort(list, n, sizeof(struct person), cmp);
    for (int i = 0; i < n; i++)
    {
        list[i].W += E[i % 10];
    }
    qsort(list, n, sizeof(struct person), cmp);
    for (int i = 0; i < k; i++)
        printf("%d%c", list[i].D, i != k - 1 ? ' ' : '\n');
    return 0;
}
