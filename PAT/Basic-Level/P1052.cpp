#include <iostream>
#include <string>
#include <vector>
int main()
{
    std::vector<std::string> data[3];
    for (int i = 0; i < 3; i++)
    {
        std::string text;
        std::getline(std::cin, text);
        for (int j = 0; j < text.length(); j++)
        {
            if (text[j] == '[')
            {
                int index = text.find("]", j);
                if (index != std::string::npos)
                {
                    data[i].push_back(text.substr(j + 1, index - j - 1));
                    j = index;
                }
            }
        }
    }
    int count;
    std::cin >> count;
    while (count--)
    {
        int a, b, c, d, e;
        std::cin >> a >> b >> c >> d >> e;
        if (a < 1 || b < 1 || c < 1 || d < 1 || e < 1 || a > data[0].size() || b > data[1].size() || c > data[2].size() || d > data[1].size() || e > data[0].size())
        {
            std::cout << "Are you kidding me? @\\/@" << std::endl;
            continue;
        }
        std::cout << data[0][--a] << "(" << data[1][--b] << data[2][--c];
        std::cout << data[1][--d] << ")" << data[0][--e] << std::endl;
    }
    return 0;
}
