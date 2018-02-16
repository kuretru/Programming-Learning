#include <stdio.h>
struct apple
{
    int xi;
    int yi;
} list[5000];
int main()
{
    int n, s, a, b;
    scanf("%d %d %d %d", &n, &s, &a, &b);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &list[i].xi, &list[i].yi);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (list[j].yi > list[j + 1].yi)
            {
                struct apple tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (list[i].xi > a + b)
            continue;
        s -= list[i].yi;
        if (s < 0)
            break;
        result++;
    }
    printf("%d", result);
    return 0;
}
