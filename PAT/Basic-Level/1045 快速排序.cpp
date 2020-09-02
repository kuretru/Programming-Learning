#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int N = 0, max = INT32_MIN;
    std::cin >> N;
    std::vector<int> raw(N), result;
    for (int i = 0; i < N; i++)
        std::cin >> raw[i];
    std::vector<int> data = raw;
    std::sort(data.begin(), data.end());
    for (int i = 0; i < N; i++)
    {
        if (raw[i] == data[i] && raw[i] > max)
            result.push_back(data[i]);
        if (raw[i] > max)
            max = raw[i];
    }
    std::cout << result.size() << std::endl;
    for (auto iter = result.begin(); iter != result.end(); iter++)
        std::cout << (iter == result.begin() ? "" : " ") << *iter;
    std::cout << std::endl;
    return 0;
}
