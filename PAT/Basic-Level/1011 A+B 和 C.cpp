#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long a, b, c;
        std::cin >> a >> b >> c;
        if (a + b > c)
            std::cout << "Case #" << i << ": true" << std::endl;
        else
            std::cout << "Case #" << i << ": false" << std::endl;
    }
    return 0;
}
