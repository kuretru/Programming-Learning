#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

int find(std::vector<int> &data, int value)
{
    if (data[value] < 0)
        return value;
    int result = find(data, data[value]);
    data[value] = result;
    return result;
}

int unionn(std::vector<int> &data, int root1, int root2)
{
    if (root1 == root2)
        return root1;
    if (root1 < root2)
    {
        data[root1] += data[root2];
        data[root2] = root1;
        return root1;
    }
    else
    {
        data[root2] += data[root1];
        data[root1] = root2;
        return root2;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int K = 0, N = 0, M = 0;
    std::cin >> K >> N >> M;
    std::vector<std::vector<int>> data(N + 1, std::vector<int>(N + 1, 0));
    while (M--)
    {
        int caller = 0, receiver = 0, duration = 0;
        std::cin >> caller >> receiver >> duration;
        data[caller][receiver] += duration;
    }
    std::vector<int> loser;
    for (int i = 1; i <= N; i++)
    {
        int called = 0, recall = 0;
        for (int j = 1; j <= N; j++)
        {
            if (data[i][j] > 0 && data[i][j] <= 5)
            {
                called++;
                if (data[j][i] > 0)
                    recall++;
            }
        }
        if (called == 0 || called <= K)
            continue;
        if (recall * 1.0 / called <= 0.2)
            loser.push_back(i);
    }

    // 诈骗犯查找结束，处理数据输出，并查集
    std::vector<int> sets(loser.size(), -1);
    for (int i = 0; i < loser.size(); i++)
    {
        int root1 = find(sets, i);
        for (int j = i + 1; j < loser.size(); j++)
            if (data[loser[i]][loser[j]] > 0 && data[loser[j]][loser[i]] > 0)
                root1 = unionn(sets, root1, find(sets, j));
    }
    std::map<int, std::vector<int>> result, tmp;
    for (int i = 0; i < loser.size(); i++)
        result[find(sets, i)].push_back(loser[i]);
    for (auto pair : result)
    {
        std::sort(pair.second.begin(), pair.second.end());
        for (auto iter = pair.second.begin(); iter != pair.second.end(); iter++)
            std::cout << *iter << (iter != pair.second.end() - 1 ? " " : "\n");
    }
    if (loser.empty())
        std::cout << "None" << std::endl;
    return 0;
}
