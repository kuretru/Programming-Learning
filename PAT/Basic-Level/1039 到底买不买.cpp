#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<char> shop;
    std::string bead = "";
    std::getline(std::cin, bead);
    for (int i = 0; i < bead.length(); i++)
        shop.push_back(bead[i]);
    std::getline(std::cin, bead);
    int count = 0;
    for (int i = 0; i < bead.length(); i++)
    {
        auto index = find(shop.begin(), shop.end(), bead[i]);
        if (index != shop.end())
            shop.erase(index);
        else
            count++;
    }
    if (count != 0)
        std::cout << "No " << count << std::endl;
    else
        std::cout << "Yes " << shop.size() << std::endl;
    return 0;
}
