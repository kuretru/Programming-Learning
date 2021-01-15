#include <algorithm>
#include <cstdio>
#include <vector>

struct station
{
    double price = 0;
    double distance = 0;

    bool operator<(const station &y) const
    {
        if (distance != y.distance)
            return distance < y.distance;
        return price < y.price;
    }
};

int main()
{
    double C = 0, D = 0, A = 0;
    int index = 0, N = 0;
    scanf("%lf %lf %lf %d", &C, &D, &A, &N);
    std::vector<station> stations(N + 1);
    for (int i = 0; i < N; i++)
        scanf("%lf %lf", &(stations[i].price), &(stations[i].distance));
    std::sort(stations.begin(), stations.end() - 1);
    stations[N].distance = D;
    if (stations.front().distance > 0)
    {
        puts("The maximum travel distance = 0.00");
        return 0;
    }

    double result = 0, gas = 0, location = 0, maxDistance = C * A;
    while (index <= N && location < D)
    {
        // 存在能到达的更便宜的加油站，加刚好达到第一个更便宜的加油站的油量
        int min = -1;
        for (int i = index + 1; min == -1 && i <= N; i++)
        {
            if (stations[i].distance - stations[index].distance > maxDistance)
                break;
            if (stations[i].price < stations[index].price)
                min = i;
        }
        if (min != -1)
        {
            double needGas = (stations[min].distance - location) * 1.0 / A - gas;
            result += needGas * stations[index].price;
            gas = 0;
            location = stations[min].distance;
            index = min;
            continue;
        }

        // 不存在能到达的更便宜的加油站，无脑加满，然后前往能到达的价格最少的加油站
        min = -1;
        for (int i = index + 1; i <= N; i++)
        {
            if (stations[i].distance - stations[index].distance > maxDistance)
                break;
            if (min == -1 || stations[i].price < stations[min].price)
                min = i;
        }
        if (min == -1)
        {
            // 没有能够到达的加油站，强行前往最远的地方
            location += maxDistance;
            break;
        }
        result += (C - gas) * stations[index].price;
        gas = C - (stations[min].distance - location) / A;
        location = stations[min].distance;
        index = min;
    }
    if (location < D)
        printf("The maximum travel distance = %.2lf\n", location);
    else
        printf("%.2lf\n", result);
    return 0;
}
