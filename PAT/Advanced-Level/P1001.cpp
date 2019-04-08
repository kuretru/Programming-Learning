#include <iostream>
#include <vector>
int main()
{
    int a, b;
    bool isNegative = false;
    std::vector<int> data;
    std::cin >> a >> b;
    if ((a += b) < 0)
    {
        isNegative = true;
        a = -a;
    }
    if (a == 0)
        data.push_back(0);
    while (a > 0)
    {
        data.push_back(a % 1000);
        a /= 1000;
    }
    if (isNegative)
        std::cout << "-";
    bool first = true;
    while (!data.empty())
    {
        if (first)
        {
            printf("%d", data.back());
            first = false;
        }
        else
            printf("%03d", data.back());
        data.pop_back();
        std::cout << (data.empty() ? "\n" : ",");
    }
    return 0;
}
