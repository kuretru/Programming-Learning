#include <iostream>
#include <set>
#include <string>

int main()
{
    std::set<char> appeared;
    std::string text;
    for (int i = 0; i < 2; i++)
    {
        std::getline(std::cin, text);
        for (int j = 0; j < text.length(); j++)
        {
            if (appeared.count(text[j]))
                continue;
            std::cout << text[j];
            appeared.insert(text[j]);
        }
    }
    return 0;
}
