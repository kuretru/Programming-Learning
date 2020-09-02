#include <algorithm>
#include <iostream>
#include <map>

int main()
{
    std::map<int, int> data;
    int count = 0, group = 0, player = 0, score = 0;
    std::cin >> count;
    while (count--)
    {
        scanf("%d-%d %d", &group, &player, &score);
        data[group] += score;
    }
    int max = data.begin()->first;
    for (auto iter = data.begin(); iter != data.end(); iter++)
        if (iter->second > data[max])
            max = iter->first;
    std::cout << max << " " << data[max] << std::endl;
    return 0;
}
