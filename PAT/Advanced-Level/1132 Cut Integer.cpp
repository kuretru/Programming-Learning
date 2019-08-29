#include <iostream>

int main()
{
    int N = 0;
    std::cin >> N;
    while (N--)
    {
        int number = 0, length = 0, pow = 1;
        std::cin >> number;
        for (int i = number; i > 0; i /= 10)
            length++;
        length >>= 1;
        for (int i = 0; i < length; i++)
            pow *= 10;
        int A = number / pow, B = number % pow;
        bool result = true;
        if (A == 0 || B == 0)
            result = false;
        else
            result = number % (A * B) == 0;
        std::cout << (result ? "Yes" : "No") << std::endl;
    }
    return 0;
}
