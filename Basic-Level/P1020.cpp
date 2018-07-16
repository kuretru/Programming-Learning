#include <algorithm>
#include <iostream>
struct cake
{
    double inventory, total, price;
    bool operator<(const cake &y)
    {
        return price > y.price;
    }
};
int main()
{
    int N, D;
    double result = 0;
    std::cin >> N >> D;
    cake *data = new cake[N];
    for (int i = 0; i < N; i++)
        std::cin >> data[i].inventory;
    for (int i = 0; i < N; i++)
        std::cin >> data[i].total;
    for (int i = 0; i < N; i++)
        data[i].price = data[i].total / data[i].inventory;
    std::sort(data, data + N);
    for (int i = 0; i < N && D > 0; i++)
    {
        if (D > data[i].inventory)
            result += data[i].total;
        else
            result += D * data[i].price;
        D -= data[i].inventory;
    }
    printf("%.2lf\n", result);
    return 0;
}
