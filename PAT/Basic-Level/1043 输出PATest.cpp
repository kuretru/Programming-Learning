#include <iostream>
#include <map>
#include <string>

const char *keys = "PATest";

int main()
{
    std::map<char, int> data;
    std::string text = "";
    std::cin >> text;
    for (int i = 0; i < text.length(); i++)
        data[text[i]]++;
    while (true)
    {
        bool finished = true;
        for (int i = 0; i < 6; i++)
        {
            if (data[keys[i]]-- > 0)
            {
                std::cout << keys[i];
                finished = false;
            }
        }
        if (finished)
            break;
    }
    return 0;
}
