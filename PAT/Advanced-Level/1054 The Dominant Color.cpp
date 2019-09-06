#include <iostream>
#include <map>

int main()
{
    std::map<int, int> data;
    int M = 0, N = 0, color = 0;
    std::cin >> M >> N;
    int half = M * N / 2;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> color;
            data[color]++;
        }
    }
    for (auto pair : data)
        if (pair.second > half)
            std::cout << pair.first << std::endl;
    return 0;
}
