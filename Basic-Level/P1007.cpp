#include <cmath>
#include <iostream>
int isPrime(int n)
{
    int length = sqrt(n);
    for (int i = 2; i <= length; i++)
        if (n % i == 0)
            return false;
    return n > 1;
}
int main()
{
    int n, count = 0, last = 1;
    std::cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
        {
            if (i - last == 2)
                count++;
            last = i;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
