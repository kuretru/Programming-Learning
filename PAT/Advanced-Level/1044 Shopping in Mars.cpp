#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    int N = 0, M = 0;
    std::cin >> N >> M;
    std::vector<int> data(N + 2);
    std::vector<int> result;
    for (int i = 1; i <= N; i++)
        std::cin >> data[i];

    int sum = 0, min = INT32_MAX;
    for (int i = 1, j = 1; i <= N && j <= N + 1;)
    {
        while (sum < M)
            sum += data[j++];

        if (sum < min)
        {
            min = sum;
            result.clear();
        }
        if (sum == min)
        {
            result.push_back(i);
            result.push_back(j - 1);
        }
        sum -= data[i++];
    }

    for (auto iter = result.begin(); iter != result.end(); iter++)
        std::cout << *(iter++) << "-" << *iter << std::endl;
    return 0;
}
