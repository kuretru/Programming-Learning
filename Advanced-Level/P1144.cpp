#include <iostream>
#include <set>
int main()
{
    std::set<int> data;
    int N, tmp;
    std::cin >> N;
    while (N--)
    {
        std::cin >> tmp;
        if (tmp > 0)
            data.insert(tmp);
    }
    if (data.empty())
        std::cout << 1 << std::endl;
    for (int i = 1; !data.empty(); i++)
    {
        if (i != *data.begin())
        {
            std::cout << i << std::endl;
            break;
        }
        data.erase(data.begin());
        if (data.empty())
            std::cout << i + 1 << std::endl;
    }
    return 0;
}
