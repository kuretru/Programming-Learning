#include <stdio.h>
int count, data[100];
int contains(int key)
{
    for (int i = 0; i < count; i++)
        if (data[i] == key)
            return 1;
    return 0;
}
int main()
{
    int number, ncount;
    scanf("%d", &ncount);
    for (int i = 0; i < ncount; i++)
    {
        scanf("%d", &number);
        if (!contains(number))
            data[count++] = number;
    }
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (data[j] > data[j + 1])
            {
                int tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++)
        printf("%d%c", data[i], i != count - 1 ? ' ' : '\n');
    return 0;
}
