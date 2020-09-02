#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    long N = 0, P = 0;
    std::cin >> N >> P;
    std::vector<int> data(N);
    for (int i = 0; i < N; i++)
        std::cin >> data[i];
    std::sort(data.begin(), data.end());
    int result = 1;
    for (int i = 0; i + result <= data.size(); i++)
    {
        for (int j = i + result; j < data.size(); j++)
        {
            if (data[j] > data[i] * P)
                break;
            result++;
        }
    }
    std::cout << result << std::endl;
    return 0;
}
