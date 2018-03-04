#include <stdio.h>
#include <stdlib.h>
int qcmp(const void *a, const void *b);
int cmp(int x, int y);
void mergesort();
struct player
{
    int score; //分数
    int skill; //实力值
} list[200001];
int rank[200001];
int win[100010], los[100010], wcount, lcount;
int main()
{
    int i, j;
    int N, R, Q;
    scanf("%d %d %d", &N, &R, &Q);
    N *= 2;
    for (i = 1; i <= N; i++)
        scanf("%d", &list[i].score);
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &list[i].skill);
        rank[i] = i;
    }
    qsort(rank + 1, N, sizeof(int), qcmp);
    for (i = 1; i <= R; i++)
    {
        wcount = lcount = 0;
        for (j = 1; j < N; j += 2)
        {
            if (list[rank[j]].skill > list[rank[j + 1]].skill)
            {
                list[rank[j]].score++;
                win[++wcount] = rank[j];
                los[++lcount] = rank[j + 1];
            }
            else
            {
                list[rank[j + 1]].score++;
                win[++wcount] = rank[j + 1];
                los[++lcount] = rank[j];
            }
        }
        mergesort();
    }
    printf("%d", rank[Q]);
    return 0;
}
int qcmp(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    if (list[x].score == list[y].score)
        return x - y;
    return list[y].score - list[x].score;
}
int cmp(int x, int y)
{
    if (list[x].score == list[y].score)
        return x < y;
    return list[x].score > list[y].score;
}
void mergesort()
{
    int j, k, index;
    j = k = index = 1;
    while (j <= wcount && k <= lcount)
    {
        if (cmp(win[j], los[k]))
            rank[index++] = win[j++];
        else
            rank[index++] = los[k++];
    }
    while (j <= wcount)
        rank[index++] = win[j++];
    while (k <= lcount)
        rank[index++] = los[k++];
}
