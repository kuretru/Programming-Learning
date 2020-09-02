#include <iostream>

const double threshold = 1000;

int main()
{
    int count = 0;
    double tmp = 0;
    long result = 0;
    std::cin >> count;
    for (int i = 1, j = count; count-- > 0; i++, j--)
    {
        std::cin >> tmp;
        result += (long)(tmp * threshold * i * j);
    }
    printf("%.2lf\n", result / threshold);
    return 0;
}
