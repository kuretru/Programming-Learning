#include <math.h>
#include <stdio.h>
int root(int n)
{
    return (int)sqrt((float)n);
}
int prime(int n)
{
    int i, bound;
    if (n % 2 == 0)
        return (n == 2);
    if (n % 3 == 0)
        return (n == 3);
    if (n % 5 == 0)
        return (n == 5);
    bound = root(n);
    for (i = 7; i <= bound; i = i + 2)
        if (n % i == 0)
            return 0;
    return 1;
}
int main()
{
    int count = 0, data[2300];
    for (int i = 2; i < 20000; i++)
    {
        if (prime(i))
            data[count++] = i;
    }
    int number;
    scanf("%d", &number);
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            for (int k = 0; k < count; k++)
            {
                if (data[i] + data[j] + data[k] == number)
                {
                    printf("%d %d %d\n", data[i], data[j], data[k]);
                    i = j = k = count;
                }
            }
        }
    }
    return 0;
}
