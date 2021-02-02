#include <iostream>
#include <string>
#include <vector>

const std::string digits[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
const std::string units[] = {"Fu", "Yi", "Wan", "Qian", "Bai", "Shi"};
const int pows[] = {1000, 100, 10, 1};

void solve(std::vector<std::string> &result, int number, int unit, bool zero)
{
    if (number == 0)
        return;
    for (int i = 0, j = 3; i < 4; i++, j++)
    {
        int n = number / pows[i];
        number %= pows[i];
        if (n > 0)
        {
            result.push_back(digits[n]);
            if (j < 6)
                result.push_back(units[j]);
            zero = true; // 0102万
        }
        else if (number != 0 && zero)
        {
            result.push_back(digits[0]);
            zero = false;
        }
    }
    if (unit != -1)
        result.push_back(units[unit]);
}

int main()
{
    std::vector<std::string> result;
    int number = 0;
    std::cin >> number;
    if (number == 0)
    {
        std::cout << digits[0] << std::endl;
        return 0;
    }
    if (number < 0)
    {
        result.push_back(units[0]);
        number = -number;
    }
    int yi = number / 100000000;
    int wan = number / 10000 % 10000;
    int ge = number % 10000;
    solve(result, yi, 1, false);
    solve(result, wan, 2, yi > 0);
    solve(result, ge, -1, wan > 0);
    for (auto iter = result.begin(); iter != result.end(); iter++)
        std::cout << *iter << (iter != result.end() - 1 ? " " : "\n");
    return 0;
}
