#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<char, int> data;
    std::string text = "";
    getline(std::cin, text);
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] += 32;
        if (text[i] < 'a' || text[i] > 'z')
            continue;
        data[text[i]]++;
    }
    char max = data.begin()->first;
    for (auto iter = data.begin(); iter != data.end(); iter++)
    {
        if (iter->second > data[max])
            max = iter->first;
    }
    printf("%c %d\n", max, data[max]);
    return 0;
}
