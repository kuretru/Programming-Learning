#include <algorithm>
#include <iostream>
#include <vector>

struct person
{
    int parent = -1;
    int minID = 0;
    int members = 1;
    double sets = 0;
    double areas = 0;
    bool operator<(const person &y) const
    {
        if (areas != y.areas)
            return areas > y.areas;
        return minID < y.minID;
    }
};

int find(std::vector<person> &data, int key)
{
    if (key == -1)
        return -1;
    if (data[key].parent == -1)
        return key;
    int result = find(data, data[key].parent);
    data[key].parent = result;
    return result;
}

int unionn(std::vector<person> &data, int root1, int root2)
{
    if (root1 == root2 || root2 == -1)
        return root1;
    int small = data[root1].members < data[root2].members ? root1 : root2;
    int big = data[root1].members >= data[root2].members ? root1 : root2;
    data[small].parent = big;
    data[big].minID = std::min(data[big].minID, data[small].minID);
    data[big].members += data[small].members;
    data[big].sets += data[small].sets;
    data[big].areas += data[small].areas;
    return big;
}

int main()
{
    std::vector<person> data(10000);
    for (int i = 0; i < 10000; i++)
        data[i].minID = i;
    int N;
    std::cin >> N;
    while (N--)
    {
        int id, father, mother, k, key, sets, areas;
        std::cin >> id >> father >> mother >> k;
        int root1 = find(data, id);
        int root2 = find(data, father);
        root1 = unionn(data, root1, root2);
        root2 = find(data, mother);
        root1 = unionn(data, root1, root2);
        while (k--)
        {
            std::cin >> key;
            root2 = find(data, key);
            root1 = unionn(data, root1, root2);
        }
        std::cin >> sets >> areas;
        data[root1].minID = std::min(data[root1].minID, id);
        data[root1].sets += sets;
        data[root1].areas += areas;
    }
    std::vector<person> result;
    for (auto p : data)
    {
        if (p.sets > 0 && p.parent == -1)
        {
            p.sets /= p.members;
            p.areas /= p.members;
            result.push_back(p);
        }
    }
    std::sort(result.begin(), result.end());
    std::cout << result.size() << std::endl;
    for (auto p : result)
        printf("%04d %d %.3lf %.3lf\n", p.minID, p.members, p.sets, p.areas);
    return 0;
}
