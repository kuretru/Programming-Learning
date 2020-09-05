#include <algorithm>
#include <iostream>
#include <string>

std::string add(const std::string &x, const std::string &y)
{
    std::string result = "";
    int carry = 0;
    for (int i = x.length() - 1; i >= 0; i--)
    {
        int n = x[i] - '0' + y[i] - '0' + carry;
        carry = n / 10;
        result = (char)(n % 10 + '0') + result;
    }
    if (carry > 0)
        result = (char)(carry + '0') + result;
    return result;
}

std::string reverse(std::string text)
{
    std::reverse(text.begin(), text.end());
    return text;
}

int main()
{
    std::string N = "";
    int K = 0, step = 0;
    std::cin >> N >> K;
    for (; step < K && N != reverse(N); step++)
    {
        std::string reversed = reverse(N);
        N = add(N, reversed);
    }
    std::cout << N << std::endl
              << step << std::endl;
    return 0;
}
