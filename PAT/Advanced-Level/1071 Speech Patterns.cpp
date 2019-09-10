#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>

int main()
{
    std::string text = "";
    std::getline(std::cin, text);
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);
    std::map<std::string, int> result;
    int start = -1;
    for (int i = 0; i < text.length(); i++)
    {
        if (isalnum(text[i]) && start == -1)
            start = i;
        if (!isalnum(text[i]) && start != -1)
        {
            result[text.substr(start, i - start)]++;
            start = -1;
        }
    }
    if (start != -1)
        result[text.substr(start)]++;
    std::string max = result.begin()->first;
    for (auto iter : result)
        if (iter.second > result[max])
            max = iter.first;
    std::cout << max << " " << result[max] << std::endl;
    return 0;
}
