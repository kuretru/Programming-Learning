#include <stdio.h>
int score[5][5] = {{0, -1, 1, 1, -1}, {1, 0, -1, 1, -1}, {-1, 1, 0, -1, 1}, {-1, -1, 1, 0, 1}, {1, 1, -1, -1, 0}};
struct player
{
    int data[200];
    int count;
    int score;
    int index;
};
int compare(int a, int b)
{
    return score[a][b];
}
int main()
{
    int groups;
    struct player A, B;
    scanf("%d %d %d", &groups, &A.count, &B.count);
    for (int i = 0; i < A.count; i++)
        scanf("%d", &A.data[i]);
    for (int i = 0; i < B.count; i++)
        scanf("%d", &B.data[i]);
    A.score = A.index = B.score = B.index = 0;
    for (int i = 0; i < groups; i++)
    {
        int result = compare(A.data[A.index++], B.data[B.index++]);
        if (result == 1)
            A.score++;
        else if (result == -1)
            B.score++;
        if (A.index >= A.count)
            A.index = 0;
        if (B.index >= B.count)
            B.index = 0;
    }
    printf("%d %d", A.score, B.score);
    return 0;
}
