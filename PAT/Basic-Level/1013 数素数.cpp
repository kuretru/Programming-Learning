#include <cmath>
#include <iostream>

int is_prime(int n)
{
    int length = sqrt(n);
    for (int i = 2; i <= length; i++)
        if (n % i == 0)
            return false;
    return n > 1;
}

int main()
{
    int count = 0, display = 0, begin = 0, end = 0;
    std::cin >> begin >> end;
    for (int i = 2; count < end; i++)
    {
        if (is_prime(i))
        {
            count++;
            if (count >= begin)
                std::cout << i << (display++ % 10 != 9 && count < end ? " " : "\n");
        }
    }
    return 0;
}
