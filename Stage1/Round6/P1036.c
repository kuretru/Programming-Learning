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
int data[20], flag[20] = {0};
int n, k;
int sum = 0, result = 0;
void calc(int step, int last)
{
    if (step == k && prime(sum))
    {
        result++;
        return;
    }
    for (int i = last; i < n; i++)
    {
        if (!flag[i])
        {
            flag[i] = 1;
            sum += data[i];
            calc(step + 1, i + 1);
            sum -= data[i];
            flag[i] = 0;
        }
    }
}
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &data[i]);
    calc(0, 0);
    printf("%d", result);
    return 0;
}
