#include <stdio.h>
struct point
{
    int a;
    int b;
    int g;
    int k;
} points[10001];
int main()
{
    int n, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d %d %d", &points[i].a, &points[i].b,
              &points[i].g, &points[i].k);
    scanf("%d %d", &x, &y);
    for (int i = n; i >= 1; i--)
    {
        if (points[i].a <= x && points[i].a + points[i].g >= x &&
            points[i].b <= y && points[i].b + points[i].k >= y)
        {
            printf("%d", i);
            break;
        }
        if (i == 1)
            printf("-1");
    }
    return 0;
}
