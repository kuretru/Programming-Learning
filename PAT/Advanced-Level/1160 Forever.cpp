#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using std::map;

const int prime[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int sum(int number)
{
    int result = 0;
    while (number > 0)
    {
        result += number % 10;
        number /= 10;
    }
    return result;
}

bool gcd(int m, int n)
{
    if (m > n)
        std::swap(m, n);
    for (int i = 23; i >= 0; i--)
    {
        if (prime[i] > m)
            continue;
        if (m % prime[i] == 0 && n % prime[i] == 0)
        {
            for (int j = prime[i] + 1; j <= m; j++)
                if (m % j == 0 && n % j == 0)
                    return false;
            return true;
        }
    }
    return false;
}

void solve(map<int, std::vector<int>> &result, int K, int m, int sums, int number, int index)
{
    if (sums > m || m - sums > (K - index) * 9 || m > 9 * K)
        return;
    if (index == K)
    {
        if (sum(number) != m)
            return;
        int n = sum(number + 1);
        if (gcd(m, n))
            result[n].push_back(number);
    }
    else
    {
        for (int i = 0; i <= 9; i++)
        {
            if (index == 0 && i == 0)
                continue;
            solve(result, K, m, sums + i, number * 10 + i, index + 1);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int N = 0;
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        std::cout << "Case " << i << std::endl;
        int K = 0, m = 0;
        std::cin >> K >> m;
        map<int, std::vector<int>> result;
        solve(result, K, m, 0, 0, 0);
        if (result.empty())
            std::cout << "No Solution" << std::endl;
        for (auto pair : result)
            for (int data : pair.second)
                std::cout << pair.first << " " << data << std::endl;
    }
    return 0;
}
