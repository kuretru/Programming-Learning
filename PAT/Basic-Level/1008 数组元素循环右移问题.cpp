#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int N = 0, M = 0;
    std::cin >> N >> M;
    std::vector<int> data(N);
    for (int i = 0; i < N; i++)
        std::cin >> data[i];
    M %= N;
    std::reverse(data.begin(), data.begin() + N - M);
    std::reverse(data.begin() + N - M, data.end());
    std::reverse(data.begin(), data.end());
    for (auto iter = data.begin(); iter != data.end(); iter++)
        std::cout << *iter << (iter != data.end() - 1 ? " " : "\n");
    return 0;
}
