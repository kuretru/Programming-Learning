#include <iostream>
int main()
{
    int count;
    double tmp, result = 0;
    std::cin >> count;
    count++;
    for (int i = 1; i < count; i++)
    {
        std::cin >> tmp;
        result += tmp * i * (count - i);
    }
    printf("%.2lf\n", result);
    return 0;
}
