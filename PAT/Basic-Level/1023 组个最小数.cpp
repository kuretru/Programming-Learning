#include <iostream>

int main()
{
    int count[10] = {0};
    for (int i = 0; i < 10; i++)
        std::cin >> count[i];
    for (int i = 1; i < 10; i++)
    {
        if (count[i] > 0)
        {
            count[i]--;
            std::cout << i;
            break;
        }
    }
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < count[i]; j++)
            std::cout << i;
    std::cout << std ::endl;
    return 0;
}
