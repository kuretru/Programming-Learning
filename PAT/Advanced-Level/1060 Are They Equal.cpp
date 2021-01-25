#include <iostream>
#include <string>

using std::string;

string standardize(string text, int N)
{
    int exponent = 0;
    int dotIndex = text.find(".");
    if (dotIndex != -1)
        text.erase(dotIndex, 1);
    int firstDigit = text.find_first_not_of("0");
    if (firstDigit != -1)
        text = text.substr(firstDigit);

    if (firstDigit == -1)
        exponent = 0;
    else if (dotIndex == -1)
        exponent = text.length();
    else
        exponent = dotIndex - firstDigit;

    while (text.length() < N)
        text += "0";
    text = text.substr(0, N);
    text = "0." + text + "*10^" + std::to_string(exponent);
    return text;
}

int main()
{
    int N = 0;
    string A = "", B = "";
    std::cin >> N >> A >> B;
    A = standardize(A, N);
    B = standardize(B, N);
    if (A == B)
        std::cout << "YES " << A << std::endl;
    else
        std::cout << "NO " << A << " " << B << std::endl;
    return 0;
}
