#include <iostream>
#include <string>

int main()
{
    std::string result = "";
    int A = 0, B = 0, D = 0;
    std::cin >> A >> B >> D;
    A += B;
    if (A == 0)
        std::cout << 0;
    while (A > 0)
    {
        result = (char)(A % D + '0') + result;
        A /= D;
    }
    std::cout << result << std::endl;
    return 0;
}
