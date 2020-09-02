#include <iostream>
#include <string>

int main()
{
    std::string result = "";
    int N = 0, count = 0;
    std::cin >> result >> N;
    while (--N)
    {
        std::string text = "";
        for (int i = 0; i < result.length(); i += count)
        {
            char c = result[i];
            count = 1;
            for (int j = i + 1; j < result.length(); j++)
            {
                if (result[j] == result[j - 1])
                    count++;
                else
                    break;
            }
            text += c;
            text += count + '0';
        }
        result = text;
    }
    std::cout << result << std::endl;
    return 0;
}
