#include <stdio.h>
int count, data[100], tag[100];
int contains(int number)
{
    for (int i = 0; i < count; i++)
    {
        if (data[i] == number)
        {
            if (!tag[i])
            {
                tag[i] = 1;
                return 1;
            }
            else
                break;
        }
    }
    return 0;
}
int main()
{
    int result = 0;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
        scanf("%d", &data[i]);
    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if (contains(data[i] + data[j]))
                result++;
    printf("%d", result);
    return 0;
}
