#include <iostream>
#include <string>

int main()
{
    std::string text = "";
    int result = 0, count = 0, p = 0;
    std::cin >> text;
    for (unsigned int i = 0; i < text.size(); i++)
    {
        if (text[i] == 'P')
            p++;
        else if (text[i] == 'A')
            count += p;
        else if (text[i] == 'T')
            result = (result + count) % 1000000007;
    }
    std::cout << result << std::endl;
    return 0;
}
