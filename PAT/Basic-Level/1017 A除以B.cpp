#include <iostream>
#include <string>

int main()
{
    std::string A = "";
    int B = 0, R = 0;
    bool first = true;
    std::cin >> A >> B;
    for (int i = 0; i < A.length(); i++)
    {
        R = R * 10 + A[i] - '0';
        if (R / B != 0 || (R / B == 0 && (!first || A.length() == 1)))
            std::cout << R / B;
        R %= B;
        first = false;
    }
    std::cout << " " << R << std::endl;
    return 0;
}
