#include <iostream>
#include <set>
int main()
{
    std::set<int> result;
    int count, tmp;
    std::cin >> count;
    while (count--)
    {
        std::cin >> tmp;
        int sum = 0;
        while (tmp > 0)
        {
            sum += tmp % 10;
            tmp /= 10;
        }
        result.insert(sum);
    }
    std::cout << result.size() << std::endl;
    for (auto iter = result.begin(); iter != result.end(); iter++)
    {
        if (iter != result.begin())
            std::cout << " ";
        std::cout << *iter;
    }
    std::cout << std::endl;
    return 0;
}
