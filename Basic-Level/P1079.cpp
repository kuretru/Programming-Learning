#include <iostream>
#include <string>
std::string add(std::string x, std::string y)
{
    int carry = 0;
    std::string s = "";
    for (int i = x.length() - 1; i >= 0; i--)
    {
        int n = carry + x[i] + y[i] - '0' - '0';
        carry = n / 10;
        char c = (n %= 10) + '0';
        s = c + s;
    }
    if (carry > 0)
        s = "1" + s;
    return s;
}
int main()
{
    std::string number;
    std::cin >> number;
    for (int i = 0; i <= 10; i++)
    {
        if (i >= 10)
        {
            std::cout << "Not found in 10 iterations." << std::endl;
            break;
        }
        std::string reverse(number.rbegin(), number.rend());
        if (number == reverse)
        {
            std::cout << number << " is a palindromic number." << std::endl;
            break;
        }
        std::string sum = add(number, reverse);
        std::cout << number << " + " << reverse << " = " << sum << std::endl;
        number = sum;
    }
    return 0;
}
