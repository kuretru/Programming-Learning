#include <iostream>
#include <string>

std::string judge(int x, double y)
{
    if (x > y)
        return " Gai";
    else if (x < y)
        return " Cong";
    else
        return " Ping";
}

int main()
{
    int M = 0, X = 0, Y = 0;
    std::cin >> M >> X >> Y;
    for (int jia = 99; jia >= 10; jia--)
    {
        int yi = jia % 10 * 10 + jia / 10;
        double bing = abs(jia - yi) * 1.0 / X;
        if (yi == bing * Y)
        {
            std::cout << jia << judge(M, jia) << judge(M, yi) << judge(M, bing) << std::endl;
            return 0;
        }
    }
    std::cout << "No Solution" << std::endl;
    return 0;
}
