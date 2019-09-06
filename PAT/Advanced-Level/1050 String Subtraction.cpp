#include <iostream>
#include <string>
#include <unordered_set>

int main()
{
    std::ios::sync_with_stdio(false);
    std::string S1 = "", S2 = "";
    std::getline(std::cin, S1);
    std::getline(std::cin, S2);
    std::unordered_set<char> unNeed;
    for (int i = 0; i < S2.length(); i++)
        unNeed.insert(S2[i]);
    for (int i = 0; i < S1.length(); i++)
        if (!unNeed.count(S1[i]))
            std::cout << S1[i];
    std::cout << std::endl;
    return 0;
}
