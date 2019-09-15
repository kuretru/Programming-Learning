#include <iostream>
#include <unordered_map>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::vector<int> data;
    std::unordered_map<int, int> map;
    int N = 0, value = 0;
    std::cin >> N;
    while (N--)
    {
        std::cin >> value;
        if (!map.count(value))
            data.push_back(value);
        map[value]++;
    }
    int result = -1;
    for (auto iter = data.begin(); result == -1 && iter != data.end(); iter++)
        if (map[*iter] == 1)
            result = *iter;
    if (result != -1)
        std::cout << result << std::endl;
    else
        std::cout << "None" << std::endl;
    return 0;
}
