#include <stdio.h>
int N, count, data[13][13];
void setFlag(int row, int column, int flag)
{
    int j = column, k = column;
    data[row][column] += (flag > 0 ? 100 : -100) + flag;
    for (int i = row + 1; i < N; i++)
    {
        data[i][column] += flag;
        if (k < N - 1)
            data[i][++k] += flag;
        if (j > 0)
            data[i][--j] += flag;
    }
}
void print()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (data[i][j] >= 100)
            {
                printf("%d", j + 1);
                break;
            }
        }
        putchar(i != N - 1 ? ' ' : '\n');
    }
}
void DFS(int row)
{
    if (row == N)
    {
        if (count < 3)
            print();
        count++;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (data[row][i])
            continue;
        setFlag(row, i, 1);
        DFS(row + 1);
        setFlag(row, i, -1);
    }
}
int main()
{
    scanf("%d", &N);
    DFS(0);
    printf("%d\n", count);
    return 0;
}
