#include <stdio.h>
struct player
{
    int no;
    int score;
} list[5000];
int cmp(int x, int y)
{
    if (list[x].score < list[y].score)
        return 1;
    else if (list[x].score == list[y].score)
        if (list[x].no > list[y].no)
            return 1;
    return 0;
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    m *= 1.5;
    for (int i = 0; i < n; i++)
        scanf("%d %d", &list[i].no, &list[i].score);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (cmp(j, j + 1))
            {
                struct player tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }
    int scoreLine = list[m - 1].score;
    for (int i = m; i < n; i++)
    {
        if (list[i].score != scoreLine)
            break;
        m++;
    }
    printf("%d %d\n", scoreLine, m);
    for (int i = 0; i < m; i++)
        printf("%d %d\n", list[i].no, list[i].score);
    return 0;
}
