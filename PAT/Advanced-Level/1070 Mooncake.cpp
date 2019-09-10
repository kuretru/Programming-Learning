#include <algorithm>
#include <iostream>
#include <vector>

struct market
{
    double demand = 0;
    double price = 0;
    double profit = 0;
    bool operator<(const market &y) const
    {
        return profit > y.profit;
    }
};

int main()
{
    double N = 0, D = 0;
    std::cin >> N >> D;
    std::vector<market> data(N);
    for (int i = 0; i < N; i++)
        std::cin >> data[i].demand;
    for (int i = 0; i < N; i++)
        std::cin >> data[i].price;
    for (int i = 0; i < N; i++)
        data[i].profit = data[i].price / data[i].demand;
    std::sort(data.begin(), data.end());
    double result = 0;
    for (int i = 0; D > 0 && i < N; i++)
    {
        if (D >= data[i].demand)
            result += data[i].price;
        else
            result += D * data[i].profit;
        D -= data[i].demand;
    }
    printf("%.2lf\n", result);
    return 0;
}
