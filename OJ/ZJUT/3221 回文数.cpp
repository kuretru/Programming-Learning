#include <algorithm>
#include <iostream>
#include <string>

using std::string;

const string MAP = "0123456789ABCDEF";

string add(string x, string y, int binary)
{
    string result = "";
    int length = x.length(), carry = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        int sum = carry;
        sum += x[i] >= '0' && x[i] <= '9' ? x[i] - '0' : x[i] - 'A' + 10;
        sum += y[i] >= '0' && y[i] <= '9' ? y[i] - '0' : y[i] - 'A' + 10;
        result = MAP[sum % binary] + result;
        carry = sum / binary;
    }
    if (carry > 0)
        result = MAP[carry] + result;
    return result;
}

string get_reverse(string number)
{
    std::reverse(number.begin(), number.end());
    return number;
}

int main()
{
    int N = 0;
    string M = "";
    std::cin >> N >> M;
    for (int i = 0; i < 30; i++)
    {
        string reverse = get_reverse(M);
        if (M == reverse)
        {
            std::cout << "STEP=" << i << std::endl;
            return 0;
        }
        M = add(M, reverse, N);
    }
    std::cout << "Impossible!" << std::endl;
    return 0;
}
