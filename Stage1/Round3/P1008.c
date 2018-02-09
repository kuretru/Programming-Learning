#include <stdio.h>
int check(int number[])
{
    int data[10] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            data[number[i] % 10] = 1;
            number[i] /= 10;
        }
    }
    for (int i = 1; i < 10; i++)
    {
        if (!data[i])
            break;
        if (i == 9)
            return 1;
    }
    return 0;
}
int main()
{
    for (int i = 100; i <= 333; i++)
    {
        int data[3] = {i, i * 2, i * 3};
        if (check(data))
            printf("%d %d %d\n", i, i * 2, i * 3);
    }
    return 0;
}
