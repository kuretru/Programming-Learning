#include <iostream>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::unordered_map<int, int> data(10001);
    int N = 0, value = 0;
    std::cin >> N;
    while (N--)
    {
        std::cin >> value;
        data[value]++;
    }
    int result = -1;
    for (auto iter = data.begin(); iter != data.end(); iter++)
        if (iter->second == 1)
            result = iter->first;
    if (result != -1)
        std::cout << result << std::endl;
    else
        std::cout << "None" << std::endl;
    return 0;
}
