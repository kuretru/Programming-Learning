#include <cmath>
#include <iostream>
#include <vector>

bool prime(int key)
{
    for (int i = 2; i <= sqrt(key); i++)
        if (key % i == 0)
            return false;
    return key > 1;
}

int main()
{
    int MSize = 0, N = 0, M = 0;
    std::cin >> MSize >> N >> M;
    while (!prime(MSize))
        MSize++;
    std::vector<int> data(MSize, -1);
    while (N--)
    {
        int key = 0;
        std::cin >> key;
        for (int i = 0; i < MSize; i++)
        {
            int index = (key + i * i) % MSize;
            if (data[index] == -1)
            {
                data[index] = key;
                break;
            }
            if (i == MSize - 1)
                std::cout << key << " cannot be inserted." << std::endl;
        }
    }
    int result = 0;
    for (int i = 0; i < M; i++)
    {
        int key = 0;
        std::cin >> key;
        int time = 0;
        for (int i = 0; i < MSize; i++)
        {
            time++;
            int index = (key + i * i) % MSize;
            if (data[index] == key || data[index] == -1)
                break;
            if (i == MSize - 1)
                time++;
        }
        result += time;
    }
    printf("%.1f\n", result * 1.0 / M);
    return 0;
}
