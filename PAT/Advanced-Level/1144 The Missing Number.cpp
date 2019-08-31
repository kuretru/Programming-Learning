#include <iostream>
#include <set>

int main()
{
    std::set<int> data;
    int N = 0;
    std::cin >> N;
    while (N--)
    {
        int number = 0;
        std::cin >> number;
        if (number > 0)
            data.insert(number);
    }
    for (int i = 1;; i++)
    {
        if (!data.count(i))
        {
            std::cout << i << std::endl;
            break;
        }
    }
    return 0;
}
