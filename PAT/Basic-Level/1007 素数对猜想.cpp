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
    int n = 0, count = 0, last = 1;
    std::cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime(i))
        {
            if (i - last == 2)
                count++;
            last = i;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
