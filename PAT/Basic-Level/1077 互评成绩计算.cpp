#include <iostream>

int main()
{
    int N = 0, M = 0;
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int teacher, n, sum = 0, count = 0, max = 0, min = M;
        std::cin >> teacher;
        for (int j = 1; j < N; j++)
        {
            std::cin >> n;
            if (n < 0 || n > M)
                continue;
            sum += n;
            if (n > max)
                max = n;
            if (n < min)
                min = n;
            count++;
        }
        sum -= max + min;
        sum = (sum * 1.0 / (count - 2) + teacher) / 2 + 0.5;
        std::cout << sum << std::endl;
    }
    return 0;
}
