#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
int main()
{
    std::map<std::string, std::set<int>> data[5];
    int count, id;
    std::string key;
    std::cin >> count;
    while (count--)
    {
        scanf("%d\n", &id);
        for (int i = 0; i < 5; i++)
        {
            if (i == 2)
            {
                while (std::cin >> key)
                {
                    data[i][key].insert(id);
                    if (getchar() == '\n')
                        break;
                }
            }
            else
            {
                std::getline(std::cin, key);
                data[i][key].insert(id);
            }
        }
    }
    std::cin >> count;
    while (count--)
    {
        scanf("%d: ", &id);
        std::getline(std::cin, key);
        auto iter = data[id - 1].find(key);
        std::cout << id << ": " << key << std::endl;
        if (iter == data[id - 1].end())
            std::cout << "Not Found" << std::endl;
        else
            for (auto iterr = iter->second.begin(); iterr != iter->second.end(); iterr++)
                printf("%07d\n", *iterr);
    }
    return 0;
}
