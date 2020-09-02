#include <algorithm>
#include <iostream>
#include <string>

std::string trim(std::string text)
{
    while (text[0] == '0')
        text = text.substr(1, text.length() - 1);
    std::reverse(text.begin(), text.end());
    return text;
}

int main()
{
    std::string table = "", x = "", y = "", result = "";
    std::cin >> table >> x >> y;
    table = trim(table);
    x = trim(x);
    y = trim(y);
    if (x.length() == 0 && y.length() == 0)
        result += "0";
    int carry = 0;
    while (x.length() > 0 || y.length() > 0 || carry > 0)
    {
        int binary = table.length() == 0 || table[0] == 'd' || table[0] == '0' ? 10 : table[0] - '0';
        int a = x.length() > 0 ? x[0] - '0' : 0;
        int b = y.length() > 0 ? y[0] - '0' : 0;
        int number = a + b + carry;
        result = (char)(number % binary + '0') + result;
        carry = number / binary;
        if (table.length() > 0)
            table = table.substr(1, table.length() - 1);
        if (x.length() > 0)
            x = x.substr(1, x.length() - 1);
        if (y.length() > 0)
            y = y.substr(1, y.length() - 1);
    }

    std::cout << result << std::endl;
    return 0;
}
