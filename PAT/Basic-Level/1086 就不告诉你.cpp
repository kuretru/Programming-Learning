#include <iostream>

int main()
{
    int A = 0, B = 0, result = 0;
    std::cin >> A >> B;
    A *= B;
    while(A>0)
    {
        result = result * 10 + A % 10;
        A /= 10;
    }
    std::cout << result << std::endl;
    return 0;
}
