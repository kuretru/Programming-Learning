#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
int main()
{
    std::vector<char> broken;
    bool shift = true;
    std::string text;
    std::getline(std::cin, text);
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == '+')
            shift = false;
        else
            broken.push_back(text[i]);
    }
    std::getline(std::cin, text);
    for (int i = 0; i < text.length(); i++)
    {
        if (std::find(broken.begin(), broken.end(), toupper(text[i])) != broken.end())
            continue;
        if (text[i] >= 'A' && text[i] <= 'Z' && !shift)
            continue;
        std::cout << text[i];
    }
    std::cout << std::endl;
    return 0;
}
