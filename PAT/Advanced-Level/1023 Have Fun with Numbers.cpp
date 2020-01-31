#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string number, doubled;
    std::cin >> number;
    std::vector<int> count(10);
    for (int i = 0; i < number.length(); i++)
        count[number[i] - '0']++;
    int carry = 0;
    for (int i = number.length() - 1; i >= 0; i--)
    {
        int n = (int)(number[i] - '0') * 2 + carry;
        carry = n / 10;
        n %= 10;
        doubled = (char)(n + '0') + doubled;
    }
    if (carry > 0)
        doubled = (char)(carry + '0') + doubled;
    for (int i = 0; i < doubled.length(); i++)
        count[doubled[i] - '0']--;
    bool result = true;
    for (int i = 0; i < 10; i++)
        if (count[i] != 0)
            result = false;
    std::cout << (result ? "Yes" : "No") << std::endl;
    std::cout << doubled << std::endl;
    return 0;
}
