#include <iostream>
#include <string>

int main()
{
    int N = 0;
    std::string option;
    std::cin >> N;
    while (N--)
    {
        for (int i = 0; i < 4; i++)
        {
            std::cin >> option;
            if (option[2] == 'T')
                std::cout << (char)(option[0] - 16);
        }
    }
    std::cout << std::endl;
    return 0;
}
