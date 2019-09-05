#include <iostream>
#include <map>
#include <string>

std::map<char, int> stat(std::string text)
{
    std::map<char, int> data;
    for (char c : text)
        data[c]++;
    return data;
}

int main()
{
    std::string shop = "", want = "";
    std::cin >> shop >> want;
    std::map<char, int> shopMap = stat(shop);
    std::map<char, int> wantMap = stat(want);
    int miss = 0;
    for (auto pair : wantMap)
        if (shopMap[pair.first] < pair.second)
            miss += pair.second - shopMap[pair.first];
    if (miss == 0)
        std::cout << "Yes " << shop.size() - want.size() << std::endl;
    else
        std::cout << "No " << miss << std::endl;
    return 0;
}
