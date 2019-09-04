#include <iostream>
#include <numeric>
#include <vector>

using std::vector;

int pow(int n, int power)
{
    int result = n;
    for (int i = 1; i < power; i++)
        result *= n;
    return result;
}

int sum(vector<int> &coef, std::vector<int> &data, int step)
{
    int sum = 0;
    for (int i = 0; i <= step; i++)
        sum += data[coef[i]];
    return sum;
}

bool compare(std::vector<int> &x, std::vector<int> &y)
{
    int sumX = std::accumulate(x.begin(), x.end(), 0);
    int sumY = std::accumulate(y.begin(), y.end(), 0);
    if (sumX != sumY)
        return sumX > sumY;
    return x > y; // 此处直接利用vector的比较
}

void solve(vector<int> &data, vector<int> &coef, std::vector<int> &result, int start, int step, int N)
{
    for (int i = start; i > 0; i--)
    {
        coef[step] = i;
        int sums = sum(coef, data, step);
        if (sums > N)
            continue;
        if (step < coef.size() - 1)
            solve(data, coef, result, i, step + 1, N);
        else if (sums == N && compare(coef, result))
            result = coef;
    }
}

int main()
{
    int N = 0, K = 0, P = 0;
    std::cin >> N >> K >> P;
    std::vector<int> coef(K), data;
    for (int i = 0; i <= N; i++)
    {
        int product = pow(i, P);
        if (product > N)
            break;
        data.push_back(product);
    }
    std::vector<int> result(K);
    solve(data, coef, result, data.size() - 1, 0, N);
    if (result[0] != 0)
    {
        std::cout << N << " =";
        for (auto iter = result.begin(); iter != result.end(); iter++)
        {
            if (iter != result.begin())
                std::cout << " +";
            std::cout << " " << *iter << "^" << P;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "Impossible" << std::endl;
    return 0;
}
