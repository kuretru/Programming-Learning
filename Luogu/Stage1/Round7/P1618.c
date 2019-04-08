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
    int A, B, C, count = 0;
    scanf("%d %d %d", &A, &B, &C);
    for (int i = 100; i <= 333; i++)
    {
        int a = i;
        int b = i * B / A;
        int c = i * C / A;
        int data[3] = {a, b, c};
        if (check(data))
        {
            printf("%d %d %d\n", a, b, c);
            count++;
        }
    }
    if (!count)
        printf("No!!!");
    return 0;
}
