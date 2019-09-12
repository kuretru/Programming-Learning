#include <iostream>
#include <vector>

int main()
{
    int N = 0, M = 0, sum = 0;
    std::cin >> N;
    std::vector<int> data(N + 2);
    for (int i = 2; i < N + 2; i++)
    {
        std::cin >> data[i];
        sum += data[i];
        data[i] = sum;
    }
    std::cin >> M;
    while (M--)
    {
        int start = 0, end = 0;
        std::cin >> start >> end;
        if (start < end)
            std::swap(start, end);
        int distance = data[start] - data[end];
        std::cout << std::min(distance, sum - distance) << std::endl;
    }
    return 0;
}
