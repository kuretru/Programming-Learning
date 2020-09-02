#include <iostream>

int main()
{
    int a = 0, b = 0;
    bool zero = true;
    while (std::cin >> a >> b)
    {
        if (b < 1)
        {
            if (zero)
                std::cout << "0 0";
            break;
        }
        if (zero)
            zero = false;
        else
            std::cout << " ";
        std::cout << a * b << " " << b - 1;
    }
    std::cout << std::endl;
    return 0;
}
