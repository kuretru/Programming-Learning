#include <iostream>

const char keys[] = "0123456789ABC";

int main()
{
    std::cout << "#";
    int color = 0;
    for (int i = 0; i < 3; i++)
    {
        std::cin >> color;
        printf("%c%c", keys[color / 13], keys[color % 13]);
    }
    std::cout << std::endl;
    return 0;
}
