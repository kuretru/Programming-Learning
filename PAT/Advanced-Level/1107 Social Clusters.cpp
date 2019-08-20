#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int find(std::vector<int> &data, int hobby)
{
    if (data[hobby] <= 0)
        return hobby;
    int root = find(data, data[hobby]);
    data[hobby] = root;
    return root;
}

void unionn(std::vector<int> &data, int root1, int root2)
{
    data[root1] += data[root2];
    data[root2] = root1;
}

int main()
{
    std::vector<int> data(1001);
    int N, count, first, key;
    char c;
    std::cin >> N;
    while (N--)
    {
        std::cin >> count >> c >> first;
        int root1 = find(data, first);
        for (int i = 1; i < count; i++)
        {
            std::cin >> key;
            int root2 = find(data, key);
            if (root1 != root2)
                unionn(data, root1, root2);
        }
        data[root1]--;
    }
    std::vector<int> result;
    for (int i = 1; i <= 1000; i++)
        if (data[i] < 0)
            result.push_back(-data[i]);
    std::sort(result.rbegin(), result.rend());
    std::cout << result.size() << std::endl;
    for (auto iter = result.begin(); iter != result.end(); iter++)
        std::cout << *iter << (iter != result.end() - 1 ? " " : "\n");
    return 0;
}
