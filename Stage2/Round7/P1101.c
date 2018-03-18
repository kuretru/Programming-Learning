#include <stdio.h>
#include <string.h>
char key[] = "izhong", text[100][102]; //开101就会错
int N, flag[100][100];
int offset[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
void markString(int row, int column, int type)
{
    for (int i = 0; i < 7; i++)
    {
        flag[row][column] = 1;
        row += offset[type][0];
        column += offset[type][1];
    }
}
void search(int row, int column)
{
    for (int i = 0; i < 8; i++)
    {
        int x = row;
        int y = column;
        for (int j = 0; j < 6; j++)
        {
            x += offset[i][0];
            y += offset[i][1];
            if (x < 0 || y < 0 || x >= N || y >= N)
                break;
            if (text[x][y] != key[j])
                break;
            if (j == 5)
                markString(row, column, i);
        }
    }
}
int main()
{
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++)
        gets(text[i]);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (text[i][j] == 'y')
                search(i, j);
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= N; j++)
            putchar(j == N ? '\n' : flag[i][j] ? text[i][j] : '*');
    return 0;
}
