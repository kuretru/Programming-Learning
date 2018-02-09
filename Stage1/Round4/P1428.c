#include <stdio.h>
int main()
{
    int count, data[100];
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
        scanf("%d", &data[i]);
    for (int i = 0; i < count; i++)
    {
        int count = 0;
        for (int j = 0; j < i; j++)
            if (data[j] < data[i])
                count++;
        printf("%d", count);
        if (i != count - 1)
            printf(" ");
    }
    return 0;
}
