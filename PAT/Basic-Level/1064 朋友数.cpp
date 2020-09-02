#include <iostream>
#include <set>

int main()
{
    std::set<int> data;
    int count = 0;
    std::cin >> count;
    while (count--)
    {
        int n = 0, sum = 0;
        std::cin >> n;
        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
        data.insert(sum);
    }
    std::cout << data.size() << std::endl;
    for (auto iter = data.begin(); iter != data.end(); iter++)
        std::cout << (iter != data.begin() ? " " : "") << *iter;
    std::cout << std::endl;
    return 0;
}
