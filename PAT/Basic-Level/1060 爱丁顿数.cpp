#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int N = 0, E = 0;
    std::cin >> N;
    std::vector<int> data(N);
    for (int i = 0; i < N; i++)
        std::cin >> data[i];
    std::sort(data.rbegin(), data.rend());
    while (data[E] > E + 1 && E < N)
        E++;
    std::cout << E << std::endl;
    return 0;
}
