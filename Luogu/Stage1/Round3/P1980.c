#include <stdio.h>
int main()
{
    int count, key, time = 0;
    scanf("%d %d", &count, &key);
    for (int i = 1; i <= count; i++)
    {
        int number = i;
        while (number > 0)
        {
            int tmp = number % 10;
            if (tmp == key)
                time++;
            number /= 10;
        }
    }
    printf("%d", time);
    return 0;
}
