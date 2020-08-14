#include <algorithm>
#include <iostream>
#include <string>

using std::string;

const int text1[3] = {0, 1, 2};
const int text2[3] = {1, 2, 0};
const int text3[3] = {2, 0, 1};

bool reverse(string text1, string text2, string text3)
{
    std::reverse(text1.begin(), text1.end());
    for (int i = 0; i < text1.length(); i++)
        if (((text2[i] + text3[i]) - 2 * (text1[i])) % 26)
            return false;
    return true;
}

int main()
{
    std::string text[3];
    std::getline(std::cin, text[0]);
    for (int i = 0; i < 3; i++)
        std::getline(std::cin, text[i]);
    for (int i = 0; i < 3; i++)
    {
        if (reverse(text[text1[i]], text[text2[i]], text[text3[i]]))
        {
            std::reverse(text[text1[i]].begin(), text[text1[i]].end());
            std::cout << text[text1[i]] << std::endl;
            break;
        }
    }
    return 0;
}
