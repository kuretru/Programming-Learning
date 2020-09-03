#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

int get_digit(char c)
{
    return isdigit(c) ? c - '0' : c - 'a' + 10;
}

long to_decimal(std::string n, int radix)
{
    long result = 0, base = 1;
    for (int i = n.length() - 1; i >= 0; i--)
    {
        int digit = get_digit(n[i]);
        result += digit * base;
        base *= radix;
    }
    return result;
}

int solve(std::string n, long target)
{
    long minRadix = get_digit(*std::max_element(n.begin(), n.end())) + 1;
    long maxRadix = std::max(target, minRadix);
    while (minRadix <= maxRadix)
    {
        long mid = (minRadix + maxRadix) / 2;
        long decimal = to_decimal(n, mid);
        if (decimal < 0 || decimal > target)
            maxRadix = mid - 1;
        else if (decimal < target)
            minRadix = mid + 1;
        else
            return mid;
    }
    return 0;
}

int main()
{
    std::string N1 = "", N2 = "";
    int tag = 0, radix = 0, result = 0;
    std::cin >> N1 >> N2 >> tag >> radix;
    if (tag != 1)
        std::swap(N1, N2);
    long target = to_decimal(N1, radix);
    result = solve(N2, target);
    if (result)
        std::cout << result << std::endl;
    else
        std::cout << "Impossible" << std::endl;
    return 0;
}
