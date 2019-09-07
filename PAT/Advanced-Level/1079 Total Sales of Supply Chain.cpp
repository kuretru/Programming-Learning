#include <iostream>
#include <vector>

using std::vector;

struct node
{
    int amount = 0;
    vector<int> children;
};

void dfs(vector<node> &data, int index, double P, double R, double &result)
{
    if (data[index].amount > 0)
        result += P * data[index].amount;
    P *= 1 + R * 0.01;
    for (int i : data[index].children)
        dfs(data, i, P, R, result);
}

int main()
{
    int N = 0;
    double P = 0, R = 0;
    std::cin >> N >> P >> R;
    vector<node> data(N);
    for (int i = 0; i < N; i++)
    {
        int count = 0;
        std::cin >> count;
        data[i].children.resize(count);
        for (int j = 0; j < count; j++)
            std::cin >> data[i].children[j];
        if (count == 0)
            std::cin >> data[i].amount;
    }
    double result = 0;
    dfs(data, 0, P, R, result);
    printf("%.1lf\n", result);
    return 0;
}
