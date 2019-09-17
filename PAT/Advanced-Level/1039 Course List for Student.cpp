#include <iostream>
#include <map>
#include <set>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::map<std::string, std::set<int>> data;
    std::string key = "";
    int N = 0, K = 0;
    std::cin >> N >> K;
    while (K--)
    {
        int course = 0, count = 0;
        std::cin >> course >> count;
        while (count--)
        {
            std::cin >> key;
            data[key].insert(course);
        }
    }
    while (N--)
    {
        std::cin >> key;
        std::cout << key << " " << data[key].size();
        for (auto iter = data[key].begin(); iter != data[key].end(); iter++)
            std::cout << " " << *iter;
        std::cout << std::endl;
    }
    return 0;
}
