#include <algorithm>
#include <iostream>
#include <string>
std::string add(std::string x, std::string y)
{
    std::string result = "";
    int carry = 0;
    for (int i = 0; i < x.size(); i++)
    {
        int a = x[i] - '0', b = y[i] - '0';
        int sum = a + b + carry;
        carry = sum / 10;
        result = (char)(sum % 10 + '0') + result;
    }
    if (carry != 0)
        result = "1" + result;
    return result;
}
int main()
{
    std::string number;
    std::cin >> number;
    for (int i = 0; i < 10; i++)
    {
        std::string rev = number;
        std::reverse(rev.begin(), rev.end());
        if (number == rev)
        {
            std::cout << number << " is a palindromic number." << std::endl;
            return 0;
        }
        std::string added = add(number, rev);
        std::cout << number << " + " << rev << " = " << added << std::endl;
        number = added;
    }
    std::cout << "Not found in 10 iterations." << std::endl;
    return 0;
}
