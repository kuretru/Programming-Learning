#include <stdio.h>
int main()
{
    int n, m, number, result = 1, sum = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &number);
        if (sum + number > m)
        {
            sum = 0;
            result++;
        }
        sum += number;
    }
    printf("%d\n", result);
    return 0;
}
