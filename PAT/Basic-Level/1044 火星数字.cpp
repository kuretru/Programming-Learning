#include <iostream>
#include <string>

std::string data[2][13] = {{"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"},
                           {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}};

int find(std::string key)
{
    for (int i = 0; i < 13; i++)
    {
        if (data[0][i] == key)
            return i;
        else if (data[1][i] == key)
            return i * 13;
    }
    return -1;
}

int main()
{
    int count;
    scanf("%d\n", &count);
    while (count--)
    {
        std::string text = "";
        std::getline(std::cin, text);
        if (isdigit(text[0]))
        {
            int number = std::stoi(text);
            if (number >= 13)
                std::cout << data[1][number / 13];
            if (number >= 13 && number % 13 != 0)
                std::cout << " ";
            if ((number >= 13 && number % 13 != 0) || number < 13)
                std::cout << data[0][number % 13];
            std::cout << std::endl;
        }
        else
        {
            int result = 0;
            if (text.length() > 4)
                result = find(text.substr(0, 3)) + find(text.substr(4, 3));
            else
                result = find(text);
            std::cout << result << std::endl;
        }
    }
    return 0;
}
