#include <iostream>
#include <vector>

int main()
{
    int N = 0, count = 0;
    std::cin >> N;
    while (N--)
    {
        std::cin >> count;
        std::vector<int> data(count + 1);
        bool yes = true;
        for (int i = 1; i <= count; i++)
        {
            std::cin >> data[i];
            for (int j = 1; j < i; j++)
            {
                if (data[j] == data[i] || abs(i - j) == abs(data[i] - data[j]))
                {
                    yes = false;
                    break;
                }
            }
        }
        std::cout << (yes ? "YES" : "NO") << std::endl;
    }
    return 0;
}
