#include <iostream>
#include <vector>

int main()
{
    int N = 0, M = 0, tmp = 0;
    std::cin >> N >> M;
    std::vector<int> data(N + 1), result;
    while (M--)
    {
        for (int i = 1; i <= N; i++)
        {
            std::cin >> tmp;
            data[i] += tmp;
        }
    }
    int max = 0;
    for (int i = 1; i <= N; i++)
    {
        if (data[i] < data[max])
            continue;
        if (data[i] > data[max])
            result.clear();
        max = i;
        result.push_back(i);
    }
    std::cout << data[max] << std::endl;
    for (auto iter = result.begin(); iter != result.end(); iter++)
        std::cout << *iter << (iter != result.end() - 1 ? " " : "\n");
    return 0;
}
