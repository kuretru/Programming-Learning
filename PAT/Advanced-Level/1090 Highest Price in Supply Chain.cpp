#include <iostream>
#include <vector>

using std::vector;

double dfs(vector<int> &data, vector<double> &result, int head, double P, double R)
{
    if (result[head] > 0)
        return result[head];
    if (data[head] == -1)
    {
        result[head] = P;
        return P;
    }
    result[head] = (1 + R * 0.01) * dfs(data, result, data[head], P, R);
    return result[head];
}

int main()
{
    int N = 0;
    double P = 0, R = 0;
    std::cin >> N >> P >> R;
    vector<int> data(N);
    for (int i = 0; i < N; i++)
        std::cin >> data[i];
    vector<double> result(N, 0);
    for (int i = 0; i < N; i++)
    {
        if (result[i] > 0)
            continue;
        dfs(data, result, i, P, R);
    }
    double max = 0;
    int count = 0;
    for (double i : result)
    {
        if (i < max)
            continue;
        if (i > max)
            count = 0;
        max = i;
        count++;
    }
    printf("%.2lf %d\n", max, count);
    return 0;
}
