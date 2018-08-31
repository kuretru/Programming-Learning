#include <iostream>
#include <map>
int main()
{
    std::map<int, int> data;
    int N, tmp;
    std::cin >> N;
    while (N--)
    {
        std::cin >> tmp;
        if (tmp > 0)
            data[tmp]++;
    }
    for (int i = 1;; i++)
    {
        if (data[i] == 0)
        {
            std::cout << i << std::endl;
            break;
        }
    }
    return 0;
}