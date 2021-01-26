#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string text = "";
    std::getline(std::cin, text);
    std::string reversed = text;
    std::reverse(reversed.begin(), reversed.end());
    std::vector<int> result(text.length(), 1);
    int length = text.length() >> 1;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < text.length(); j++)
        {
            int count = 0;
            for (int k = 0; i + k < text.length() && j + k < text.length(); k++)
            {
                if (text[i + k] != reversed[j + k])
                    break;
                count++;
            }
            result[i] = std::max(result[i], count);
        }
    }
    int max = *(std::max_element(result.begin(), result.end()));
    std::cout << max << std::endl;
    return 0;
}
