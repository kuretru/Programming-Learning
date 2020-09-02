#include <cctype>
#include <iostream>
#include <string>

int main()
{
    char function = ' ';
    std::string text = "";
    scanf("%c%*c", &function);
    std::getline(std::cin, text);
    if (function == 'C')
    {
        for (int i = 0, j = 0; i < text.length(); i = j)
        {
            int count = 1;
            for (j = i + 1; j < text.length(); j++)
            {
                if (text[j] == text[i])
                    count++;
                else
                    break;
            }
            if (count > 1)
                std::cout << count;
            std::cout << text[i];
        }
    }
    else
    {
        int count = 0;
        for (int i = 0; i < text.length(); i++)
        {
            if (isdigit(text[i]))
                count = count * 10 + (text[i] - '0');
            else
            {
                if (count == 0)
                    std::cout << text[i];
                else
                    for (; count > 0; count--)
                        std::cout << text[i];
            }
        }
    }
    std::cout << std::endl;
    return 0;
}
