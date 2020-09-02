#include <algorithm>
#include <cstdio>

bool judge(int x, int y)
{
    for (int i = std::min(x, y); i > 1; i--)
        if (x % i == 0 && y % i == 0)
            return false;
    return true;
}

int main()
{
    int N1, M1, N2, M2, K = 0, flag = 1;
    scanf("%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &K);
    double x = N1 * 1.0 / M1, y = N2 * 1.0 / M2;
    int length = (std::max(x, y)) * K;
    for (int i = std::min(x, y) * K; i <= length; i++)
    {
        double r = i * 1.0 / K;
        if (judge(i, K) && std::min(x, y) < r && r < std::max(x, y))
        {
            printf("%s%d/%d", flag == 1 ? "" : " ", i, K);
            flag = 0;
        }
    }
    printf("\n");
    return 0;
}
