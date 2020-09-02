#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> data;
    std::string text = "";
    while (std::cin >> text)
        data.push_back(text);
    for (auto iter = data.rbegin(); iter != data.rend(); iter++)
        std::cout << *iter << (iter != data.rend() - 1 ? " " : "\n");
    return 0;
}
