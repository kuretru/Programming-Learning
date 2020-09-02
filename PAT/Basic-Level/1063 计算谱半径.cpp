#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main()
{
    int N = 0, a = 0, b = 0;
    std::cin >> N;
    std::vector<double> data(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> a >> b;
        data[i] = sqrt(a * a + b * b);
    }
    double max = *max_element(data.begin(), data.end());
    printf("%.2lf\n", max);
    return 0;
}
