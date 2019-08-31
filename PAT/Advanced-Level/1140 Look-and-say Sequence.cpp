#include <iostream>
#include <string>

std::string attach(std::string text)
{
    std::string attach = "";
    char last = 'D';
    int count;
    for (int i = 0; i < text.length(); i++)
    {
        if (last == text[i])
        {
            count++;
            continue;
        }
        if (last != 'D')
        {
            attach += last + std::to_string(count);
        }
        last = text[i];
        count = 1;
    }
    attach += last + std::to_string(count);
    return attach;
}

int main()
{
    int D, N;
    std::cin >> D >> N;
    std::string text = std::to_string(D);
    while (N-- > 1)
    {
        text = attach(text);
    }
    std::cout << text << std::endl;
    return 0;
}
