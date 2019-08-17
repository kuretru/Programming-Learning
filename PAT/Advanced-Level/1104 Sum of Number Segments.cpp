#include <cstdio>
int main()
{
    int N;
    scanf("%d", &N);
    double key, result = 0;
    for (int i = 1; i <= N; i++)
    {
        scanf("%lf", &key);
        result += key * i * (N + 1 - i);
    }
    printf("%.2lf\n", result);
    return 0;
}
