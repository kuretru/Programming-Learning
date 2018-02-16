#include <stdio.h>
int data[59049][10]; //3^10
int flag[10];
int n, count;
void calc(int index)
{
    if (index > 9)
    {
        int sum = 0;
        for (int i = 0; i < 10; i++)
            sum += flag[i];
        if (sum == n)
        {
            for (int i = 0; i < 10; i++)
                data[count][i] = flag[i];
            count++;
        }
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        flag[index] = i;
        calc(index + 1);
    }
}
int main()
{
    scanf("%d", &n);
    if (n > 30)
        printf("0");
    else
    {
        calc(0);
        printf("%d\n", count);
        for (int i = 0; i < count; i++)
            for (int j = 0; j < 10; j++)
                printf("%d%c", data[i][j], j != 9 ? ' ' : '\n');
    }
    return 0;
}
