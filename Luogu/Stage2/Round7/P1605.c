#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int X;
    int Y;
} point;
int N, M, T, result, maze[7][7], offset[2][4] = {{-1, 0, 1, 0}, {0, -1, 0, 1}};
point *data, start, end;
void DFS(point current)
{
    if (current.X < 1 || current.Y < 1 || current.X > N || current.Y > M) //边界外结束
        return;
    if (maze[current.X][current.Y]) //已经过结束
        return;
    for (int i = 0; i < T; i++)
        if (current.X == data[i].X && current.Y == data[i].Y) //障碍物结束
            return;
    if (current.X == end.X && current.Y == end.Y) //到达终点
    {
        result++;
        return;
    }
    maze[current.X][current.Y] = 1;
    for (int i = 0; i < 4; i++)
    {
        point p = {current.X + offset[0][i], current.Y + offset[1][i]};
        DFS(p);
    }
    maze[current.X][current.Y] = 0;
}
int main()
{
    scanf("%d %d %d", &N, &M, &T);
    scanf("%d %d %d %d", &start.X, &start.Y, &end.X, &end.Y);
    data = (point *)malloc(T * sizeof(point));
    for (int i = 0; i < T; i++)
        scanf("%d %d", &data[i].X, &data[i].Y);
    DFS(start);
    printf("%d\n", result);
    return 0;
}
