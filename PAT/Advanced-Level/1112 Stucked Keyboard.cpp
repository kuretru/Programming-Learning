// 此题第二个测试点会有如下情况：{2 aabbcb} 此时b不是坏键

#include <iostream>
#include <set>
#include <string>

bool isBroken(std::string &text, int index, int k)
{
    int count = 1;
    for (size_t i = 1; index + i < text.size(); i++, count++)
        if (text[index + i] != text[index])
            break;
    return count % k == 0;
}

int main()
{
    int k;
    std::string text, result = "";
    std::cin >> k >> text;
    std::set<char> worked, stucked;
    for (size_t i = 0; i < text.size(); i++)
    {
        if (worked.count(text[i]))
            continue;
        if (isBroken(text, i, k))
        {
            stucked.insert(text[i]);
            i += k - 1;
        }
        else
            worked.insert(text[i]);
    }
    for (char c : worked)
        if (stucked.count(c))
            stucked.erase(c);
    for (size_t i = 0; i < text.size(); i++)
    {
        result += text[i];
        if (stucked.count(text[i]))
        {
            // 复用好键标记，标识是否输出过
            if (!worked.count(text[i]))
            {
                worked.insert(text[i]);
                std::cout << text[i];
            }
            i += k - 1;
        }
    }
    std::cout << std::endl << result << std::endl;
    return 0;
}
