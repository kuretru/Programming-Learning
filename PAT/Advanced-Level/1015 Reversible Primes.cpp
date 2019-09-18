#include <cmath>
#include <iostream>
#include <vector>

bool is_prime(int N)
{
    int length = sqrt(N);
    for (int i = 2; i <= length; i++)
        if (N % i == 0)
            return false;
    return N > 1;
}

bool is_reversible_prime(int N, const int D)
{
    if (!is_prime(N))
        return false;
    std::vector<int> series;
    for (; N > 0; N /= D)
        series.push_back(N % D);
    for (int i : series)
        N = N * D + i;
    return is_prime(N);
}

int main()
{
    int N = 0, D = 0;
    while (true)
    {
        std::cin >> N;
        if (N < 0)
            break;
        std::cin >> D;
        bool result = is_reversible_prime(N, D);
        std::cout << (result ? "Yes" : "No") << std::endl;
    }
    return 0;
}
