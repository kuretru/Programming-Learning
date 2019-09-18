#include <iostream>
#include <vector>
int main()
{
    int N, M, key;
    std::cin >> N >> M;
    std::vector<int> data(N + 1);
    data[0] = INT32_MIN;
    for (int i = 1; i <= N; i++)
    {
        std::cin >> data[i];
        for (int j = i; j > 0; j >>= 1)
        {
            key = j >> 1;
            if (data[j] < data[key])
            {
                int tmp = data[j];
                data[j] = data[key];
                data[key] = tmp;
            }
            else
            {
                break;
            }
        }
    }
    while (M--)
    {
        std::cin >> key;
        for (int i = key; i > 0; i >>= 1)
        {
            std::cout << data[i] << (i != 1 ? " " : "\n");
        }
    }
    return 0;
}
