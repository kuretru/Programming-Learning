#include <cctype>
#include <iostream>
#include <string>
int main()
{
    int count;
    scanf("%d\n", &count);
    while (count--)
    {
        std::string text;
        std::getline(std::cin, text);
        if (text.length() < 6)
        {
            std::cout << "Your password is tai duan le." << std::endl;
            continue;
        }
        int letter = 0, digit = 0, other = 0, length = text.length();
        for (int i = 0; i < length; i++)
        {
            if (isalpha(text[i]))
                letter++;
            else if (isdigit(text[i]))
                digit++;
            else if (text[i] != '.')
                other++;
        }
        if (other > 0)
            std::cout << "Your password is tai luan le." << std::endl;
        else if (letter > 0 && digit == 0)
            std::cout << "Your password needs shu zi." << std::endl;
        else if (letter == 0 && digit > 0)
            std::cout << "Your password needs zi mu." << std::endl;
        else
            std::cout << "Your password is wan mei." << std::endl;
    }
    return 0;
}
