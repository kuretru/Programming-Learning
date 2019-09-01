#include <iostream>
#include <vector>

int main()
{
    int N = 0, M = 0, K = 0;
    std::cin >> N >> M;
    std::vector<std::vector<int>> data(N + 1, std::vector<int>(N + 1, 0));
    while (M--)
    {
        int start = 0, end = 0;
        std::cin >> start >> end;
        data[start][end] = 1;
    }
    std::cin >> K;
    std::vector<int> result;
    for (int i = 0; i < K; i++)
    {
        bool notOrder = false;
        std::vector<std::vector<int>> copy = data;
        int count = N;
        while (count--)
        {
            int key = 0;
            std::cin >> key;
            if (notOrder)
                continue;
            for (int j = 1; j <= N; j++)
            {
                if (copy[j][key] == 1)
                {
                    notOrder = true;
                    break;
                }
                if (j == N)
                {
                    for (int k = 1; k <= N; k++)
                        copy[key][k] = 0;
                }
            }
        }
        if (notOrder)
            result.push_back(i);
    }
    for (auto iter = result.begin(); iter != result.end(); iter++)
        std::cout << *iter << (iter != result.end() - 1 ? " " : "\n");
    return 0;
}
