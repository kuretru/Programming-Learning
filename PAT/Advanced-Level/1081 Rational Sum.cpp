#include <cctype>
#include <iostream>
#include <string>

long long gcd(long long x, long long y)
{
    return y == 0 ? x : gcd(y, x % y);
}

struct fraction
{
    bool negative = false;
    long long numerator = 0;
    long long denominator = 0;

    void gcd_me()
    {
        long long gcd1 = gcd(this->numerator, this->denominator);
        this->numerator /= gcd1;
        this->denominator /= gcd1;
    }

    fraction(std::string text)
    {
        int start = 0;
        if (text[0] == '-')
            this->negative = true;
        if (!isdigit(text[0]) && text[0] != '/')
            start++;
        int index = text.find("/");
        this->numerator = std::stoi(text.substr(start, index - start));
        this->denominator = std::stoi(text.substr(index + 1));
        if (this->numerator != 0)
            this->gcd_me();
    }
    fraction operator+(const fraction &y)
    {
        if (this->numerator == 0)
            return y;
        if (y.numerator == 0)
            return *this;
        long long lcm = this->denominator * y.denominator / gcd(this->denominator, y.denominator);
        this->numerator *= lcm / this->denominator;
        long long y_numerator = lcm / y.denominator * y.numerator;
        this->denominator = lcm;
        if (this->negative == y.negative)
            this->numerator = this->numerator + y_numerator;
        else if (this->numerator > y.numerator)
            this->numerator = this->numerator - y_numerator;
        else
        {
            this->numerator = y_numerator - this->numerator;
            this->negative = !this->negative;
        }
        this->gcd_me();
        return *this;
    }
};

int main()
{
    int N = 0;
    std::cin >> N;
    std::string text = "0/0";
    fraction sum = fraction(text);
    while (N--)
    {
        std::cin >> text;
        sum = sum + fraction(text);
    }
    if (sum.numerator == 0)
    {
        std::cout << "0" << std::endl;
        return 0;
    }
    long long integer = sum.numerator / sum.denominator;
    sum.numerator %= sum.denominator;
    if (sum.negative)
        std::cout << "-";
    if (integer != 0)
        std::cout << integer;
    if (integer != 0 && sum.numerator != 0)
        std::cout << " ";
    if (sum.numerator != 0)
        std::cout << sum.numerator << "/" << sum.denominator << std::endl;
    return 0;
}
