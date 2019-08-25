#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int N = 0;
    std::cin >> N;
    std::vector<int> data(N);
    for (int i = 0; i < N; i++)
        std::cin >> data[i];
    std::sort(data.begin(), data.end());
    double result = data[0];
    for (int i = 1; i < N; i++)
        result = (result + data[i]) / 2;
    std::cout << (int)result << std::endl;
    return 0;
}
