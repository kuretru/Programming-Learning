#include <iostream>
#include <string>

bool judgle(std::string text)
{
    int pCount = 0, tCount = 0;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != 'P' && text[i] != 'A' && text[i] != 'T')
            return false;
        if (text[i] == 'P')
            pCount++;
        else if (text[i] == 'T')
            tCount++;
    }
    if (pCount != 1 || tCount != 1)
        return false;

    int pIndex = text.find('P');
    int tIndex = text.find('T');
    int aCount = pIndex;
    int bCount = tIndex - pIndex - 1;
    int cCount = text.length() - tIndex - 1;
    return aCount * bCount == cCount && bCount != 0;
}

int main()
{
    int n = 0;
    std::cin >> n;
    while (n--)
    {
        std::string text = "";
        std::cin >> text;
        std::cout << (judgle(text) ? "YES" : "NO") << std::endl;
    }
    return 0;
}
