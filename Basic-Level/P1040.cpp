#include <iostream>
#include <string>
int main()
{
    int count = 0, P = 0, T = 0;
    std::string text;
    std::cin >> text;
    int length = text.length();
    for (int i = 0; i < length; i++)
        if (text[i] == 'T')
            T++;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == 'P')
            P++;
        else if (text[i] == 'A')
            count = (count + P * T) % 1000000007;
        else if (text[i] == 'T')
            T--;
    }
    std::cout << count << std::endl;
    return 0;
}
