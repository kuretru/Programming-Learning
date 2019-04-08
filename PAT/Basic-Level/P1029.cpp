#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
int main()
{
    std::vector<char> found;
    std::string raw, input;
    std::cin >> raw >> input;
    std::transform(raw.begin(), raw.end(), raw.begin(), ::toupper);
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    for (int i = 0; i < raw.length(); i++)
    {
        if (input.find(raw[i]) == std::string::npos)
        {
            if (find(found.begin(), found.end(), raw[i]) == found.end())
            {
                found.push_back(raw[i]);
                putchar(raw[i]);
            }
        }
    }
    return 0;
}
