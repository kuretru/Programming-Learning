// 仅保证有一个有效记录，并不保证每一个客户至少有一个有效记录

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

const std::string ONLINE = "on-line";
std::vector<int> COSTS(25, 0);

struct record
{
    int month = 0;
    int day = 0;
    int hour = 0;
    int minute = 0;
    int time = 0;
    int type = 0; // 0->on-line 1->off-line
    bool operator<(const record &y) const
    {
        return time < y.time;
    }
};

double compute_price(const record &x)
{
    double price = x.minute * COSTS[x.hour] + x.day * 60 * COSTS[24];
    for (int i = 0; i < x.hour; i++)
        price += COSTS[i] * 60;
    return price / 100.0;
}

int main()
{
    for (int i = 0; i < 24; i++)
    {
        std::cin >> COSTS[i];
        COSTS[24] += COSTS[i];
    }
    int N = 0;
    std::cin >> N;
    std::map<std::string, std::vector<record>> data;
    while (N--)
    {
        std::string name, type;
        record r;
        std::cin >> name;
        scanf("%d:%d:%d:%d", &r.month, &r.day, &r.hour, &r.minute);
        r.time = r.day * 24 * 60 + r.hour * 60 + r.minute;
        std::cin >> type;
        r.type = type == ONLINE ? 0 : 1;
        data[name].push_back(r);
    }
    for (auto iter = data.begin(); iter != data.end(); iter++)
        std::sort(iter->second.begin(), iter->second.end());
    for (auto iter = data.begin(); iter != data.end(); iter++)
    {
        bool found = false;
        double sum = 0;
        for (int i = 1; i < iter->second.size(); i++)
        {
            record x = iter->second[i - 1], y = iter->second[i];
            if (x.type == 0 && y.type == 1)
            {
                if (!found)
                {
                    found = true;
                    printf("%s %02d\n", iter->first.data(), iter->second.front().month);
                }
                double price = compute_price(y) - compute_price(x);
                sum += price;
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",
                       x.day, x.hour, x.minute,
                       y.day, y.hour, y.minute,
                       y.time - x.time, price);
            }
        }
        if (found)
            printf("Total amount: $%.2lf\n", sum);
    }
    return 0;
}
