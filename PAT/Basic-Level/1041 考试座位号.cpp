#include <iostream>
#include <map>
#include <string>

struct examinee
{
    std::string id = "";
    int sj = 0;
    int ks = 0;
};

int main()
{
    std::map<int, examinee> data;
    int count = 0, key = 0;
    std::cin >> count;
    while (count--)
    {
        examinee e;
        std::cin >> e.id >> e.sj >> e.ks;
        data[e.sj] = e;
    }
    std::cin >> count;
    while (count--)
    {
        std::cin >> key;
        std::cout << data[key].id << " " << data[key].ks << std::endl;
    }
    return 0;
}
