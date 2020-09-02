#include <iostream>

int main()
{
    int N = 0, D = 0, may = 0, must = 0;
    float e = 0, f = 0;
    std::cin >> N >> e >> D;
    for (int i = 0; i < N; i++)
    {
        int count = 0, days = 0;
        std::cin >> count;
        for (int j = 0; j < count; j++)
        {
            std::cin >> f;
            if (f < e)
                days++;
        }
        if (days * 2 > count)
            count > D ? must++ : may++;
    }
    printf("%.1f%% %.1f%%\n", may * 100.0 / N, must * 100.0 / N);
    return 0;
}
