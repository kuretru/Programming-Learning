#include <iostream>
#include <map>

int find(std::map<int, int> &data, int key)
{
    if (!data.count(key))
        data[key] = -1;
    if (data[key] < 0)
        return key;
    int result = find(data, data[key]);
    data[key] = result;
    return result;
}

int unionn(std::map<int, int> &data, int root1, int root2)
{
    if (root1 == root2)
        return root1;
    if (data[root1] > data[root2])
    {
        data[root2] += data[root1];
        data[root1] = root2;
        return root2;
    }
    else
    {
        data[root1] += data[root2];
        data[root2] = root1;
        return root1;
    }
}

int main()
{
    std::map<int, int> data;
    int N, count, key;
    std::cin >> N;
    while (N--)
    {
        std::cin >> count;
        if (count <= 0)
            continue;
        std::cin >> key;
        int root1 = find(data, key);
        for (int i = 1; i < count; i++)
        {
            std::cin >> key;
            int root2 = find(data, key);
            root1 = unionn(data, root1, root2);
        }
    }
    int Q, treeCount = 0;
    for (auto pair : data)
    {
        if (pair.second < 0)
            treeCount++;
    }
    std::cout << treeCount << " " << data.size() << std::endl;
    std::cin >> Q;
    while (Q--)
    {
        int x, y;
        std::cin >> x >> y;
        if (find(data, x) == find(data, y))
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
    }
    return 0;
}
