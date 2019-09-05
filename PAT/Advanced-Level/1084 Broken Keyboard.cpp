#include <algorithm>
#include <iostream>
#include <set>
#include <string>

int main()
{
    std::string original = "", typed = "", result = "";
    std::cin >> original >> typed;
    std::set<char> found;
    std::transform(original.begin(), original.end(), original.begin(), ::toupper);
    std::transform(typed.begin(), typed.end(), typed.begin(), ::toupper);
    auto i = original.begin(), j = typed.begin();
    for (; i != original.end();)
    {
        if (j != typed.end() && *i == *j)
            j++;
        else if (!found.count(*i))
        {
            result += *i;
            found.insert(*i);
        }
        i++;
    }
    std::cout << result << std::endl;
    return 0;
}
