#include <iostream>
#include <map>
#include <string>

int main()
{
    int N, maxCount = 0, maxPeople = 0;
    std::cin >> N;
    N <<= 1;
    std::map<std::string, int> data;
    while (N--)
    {
        std::string key;
        std::cin >> key;
        data[key]++;
    }
    std::string maxPhone;
    for (auto iter = data.begin(); iter != data.end(); iter++)
    {
        if (iter->second < maxCount)
            continue;
        if (iter->second > maxCount || iter->first < maxPhone)
            maxPhone = iter->first;
        maxPeople = iter->second > maxCount ? 1 : maxPeople + 1;
        maxCount = iter->second;
    }
    std::cout << maxPhone << " " << maxCount << (maxPeople > 1 ? " " : "\n");
    if (maxPeople > 1)
        std::cout << maxPeople << std::endl;
    return 0;
}
