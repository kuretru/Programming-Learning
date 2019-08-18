#include <cmath>
#include <cstdio>
#include <vector>

const double MAX = 10000000000;

struct node
{
    double price = MAX;
    std::vector<int> children;
};

void build(std::vector<node> &data, int head, double price, double r)
{
    data[head].price = price;
    price *= 1 + r * 0.01;
    for (int child : data[head].children)
        build(data, child, price, r);
}

int main()
{
    int N, count, key;
    double P, r;
    scanf("%d %lf %lf", &N, &P, &r);
    std::vector<node> data(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &count);
        data[i].children.resize(count);
        for (int j = 0; j < count; j++)
            scanf("%d", &data[i].children[j]);
    }
    build(data, 0, P, r);
    double min = MAX;
    for (int i = 0; i < N; i++)
    {
        if (data[i].children.size() != 0)
            continue;
        if (data[i].price < min)
        {
            min = data[i].price;
            count = 1;
        }
        else if (data[i].price == min)
            count++;
    }
    printf("%.4lf %d\n", min, count);
    return 0;
}
