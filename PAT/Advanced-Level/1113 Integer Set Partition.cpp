#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> data(N);
    for (int i = 0; i < N; i++)
        std::cin >> data[i];
    std::sort(data.begin(), data.end());
    int sum1 = 0, sum2 = 0;
    N >>= 1;
    for (int i = 0; i < N; i++)
    {
        sum1 += data[i];
        sum2 += data[data.size() - 1 - i];
    }
    if (data.size() % 2)
        sum2 += data[N];
    std::cout << data.size() % 2 << " " << sum2 - sum1 << std::endl;
    return 0;
}
