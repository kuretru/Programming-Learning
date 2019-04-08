#include <algorithm>
#include <iostream>
#include <map>
#include <set>
int main()
{
    std::map<int, int> couple;
    std::set<int> guest;
    std::set<int> single;
    std::set<int>::iterator iter;
    int count, tmp;
    std::cin >> count;
    while (count--)
    {
        int a, b;
        std::cin >> a >> b;
        couple[a] = b;
        couple[b] = a;
    }
    std::cin >> count;
    while (count--)
    {
        std::cin >> tmp;
        guest.insert(tmp);
    }
    for (iter = guest.begin(); iter != guest.end(); iter++)
    {
        if (couple.find(*iter) == couple.end())
            single.insert(*iter);
        else if (guest.find(couple[*iter]) == guest.end())
            single.insert(*iter);
    }
    count = single.size();
    std::cout << count << std::endl;
    for (iter = single.begin(); count > 0; iter++, count--)
        printf("%05d%c", *iter, count > 1 ? ' ' : '\n');
    return 0;
}
