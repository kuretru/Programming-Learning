#include <iostream>
#include <string>
int main()
{
    char table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
    std::string secret, raw, result = "";
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
