#include <iostream>
#include <string>
#include <vector>

bool contains(std::vector<std::string> &list, std::string key)
{
    for (auto iter = list.begin(); iter != list.end(); iter++)
        if (*iter == key)
            return true;
    return false;
}

int main()
{
    std::vector<std::string> names, winner;
    std::string text;
    int M = 0, N = 0, S = 0;
    std::cin >> M >> N >> S;
    for (int i = 0; i < M; i++)
    {
        std::cin >> text;
        names.push_back(text);
    }
    for (int i = S - 1; i < M; i += N)
    {
        while (i < M && contains(winner, names[i]))
            i++;
        winner.push_back(names[i]);
    }
    for (auto iter = winner.begin(); iter != winner.end(); iter++)
        std::cout << *iter << std::endl;
    if (S > M)
        std::cout << "Keep going..." << std::endl;
    return 0;
}
