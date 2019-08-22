#include <cstring>
#include <iostream>
#include <string>
#include <vector>

int c_strstr(std::string text, std::string pattern); // 154ms
int noob(std::string text, std::string pattern);     // TLE*1
int kmp(std::string text, std::string pattern);      // 99ms

typedef int (*find_interface)(std::string text, std::string pattern);

find_interface find = kmp;

int main()
{
    int N;
    std::string text, pattern;
    std::cin >> text >> N;
    while (N--)
    {
        std::cin >> pattern;
        int index = find(text, pattern);
        if (index == -1)
            std::cout << "Not Found" << std::endl;
        else
            std::cout << text.substr(index) << std::endl;
    }
    return 0;
}

int c_strstr(std::string text, std::string pattern)
{
    const char *c_text = text.c_str();
    const char *index = strstr(c_text, pattern.c_str());
    if (index)
        return (index - c_text) / sizeof(char);
    return -1;
}

int noob(std::string text, std::string pattern)
{
    int textLength = text.length();
    int patternLength = pattern.length();
    for (int i = 0; i <= textLength - patternLength; i++)
    {
        for (int j = 0; j < patternLength; j++)
        {
            if (text[i + j] != pattern[j])
                break;
            if (j == patternLength - 1)
                return i;
        }
    }
    return -1;
}

std::vector<int> buildPMT(std::string pattern)
{
    int length = pattern.length();
    std::vector<int> pmt(length);
    pmt[0] = -1;
    for (int i = 1; i < length; i++)
    {
        int j = pmt[i - 1];
        while (j >= 0 && (pattern[j + 1] != pattern[i]))
            j = pmt[j];
        if (pattern[j + 1] == pattern[i])
            pmt[i] = j + 1;
        else
            pmt[i] = -1;
    }
    for (int i = length - 1; i > 0; i--)
        pmt[i] = pmt[i - 1] + 1;
    return pmt;
}

int kmp(std::string text, std::string pattern)
{
    std::vector<int> pmt = buildPMT(pattern);
    int textLength = text.length();
    int patternLength = pattern.length();
    for (int i = 0, j = 0; i < textLength;)
    {
        if (text[i] == pattern[j])
        {
            i++;
            if (++j == patternLength)
                return i - patternLength;
        }
        else if (j > 0)
            j = pmt[j];
        else
            i++;
    }
    return -1;
}
