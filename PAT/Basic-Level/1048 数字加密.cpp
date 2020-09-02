#include <iostream>
#include <string>

const char *table = "0123456789JQK";

int main()
{
    std::string secret = "", raw = "", result = "";
    std::cin >> secret >> raw;
    int index = 1, i = secret.length() - 1, j = raw.length() - 1;
    while (i >= 0 || j >= 0)
    {
        int a = 0, b = 0;
        if (i >= 0)
            a = secret[i--] - '0';
        if (j >= 0)
            b = raw[j--] - '0';
        if (index++ % 2 == 1)
            result = table[(a + b) % 13] + result;
        else
        {
            b -= a;
            if (b < 0)
                b += 10;
            result = (char)(b + '0') + result;
        }
    }
    std::cout << result << std::endl;
    return 0;
}
