#include <stdio.h>
int main()
{
    int n, avg = 0, data[100], count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
        avg += data[i];
    }
    avg /= n;
    for (int i = 0; i < n; i++)
        data[i] -= avg;
    for (int i = 0; i < n - 1; i++)
    {
        if (data[i] != 0)
        {
            data[i + 1] += data[i];
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
