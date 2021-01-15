#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

struct person
{
    string name = "";
    int times = 0;
    person(string name)
    {
        this->name = name;
    }
    bool operator<(const person &y) const
    {
        return times > y.times;
    }
};

struct gang
{
    string headName = "";
    int count = 0;
    gang(string headName, int count)
    {
        this->headName = headName;
        this->count = count;
    }
    bool operator<(const gang &y) const
    {
        return headName < y.headName;
    }
};

int get_index(unordered_map<string, int> &map, vector<person> &data, vector<int> &set, string name)
{
    if (!map.count(name))
    {
        map[name] = data.size();
        set.push_back(-1);
        data.push_back(person(name));
    }
    return map[name];
}

int find(vector<int> &data, int index)
{
    if (data[index] < 0)
        return index;
    int root = find(data, data[index]);
    data[index] = root;
    return root;
}

void unionn(vector<int> &data, int rootX, int rootY)
{
    if (rootX > rootY)
    {
        data[rootY] += data[rootX];
        data[rootX] = rootY;
    }
    else
    {
        data[rootX] += data[rootY];
        data[rootY] = rootX;
    }
}

int main()
{
    int N = 0, K = 0, time = 0;
    std::cin >> N >> K;
    unordered_map<string, int> map;
    vector<int> set;
    vector<person> data;
    for (int i = 0; i < N; i++)
    {
        string a = "", b = "";
        std::cin >> a >> b >> time;
        int aIndex = get_index(map, data, set, a);
        int bIndex = get_index(map, data, set, b);
        data[aIndex].times += time;
        data[bIndex].times += time;
        int aRoot = find(set, aIndex);
        int bRoot = find(set, bIndex);
        if (aRoot != bRoot)
            unionn(set, aRoot, bRoot);
    }

    // 归并每个党派
    unordered_map<int, vector<int>> gangs;
    for (int i = 0; i < set.size(); i++)
    {
        int root = find(set, i);
        if (!gangs.count(root))
            gangs[root] = vector<int>();
        gangs[root].push_back(i);
    }

    // 找出每个党派的首领
    vector<gang> result;
    for (auto iter = gangs.begin(); iter != gangs.end(); iter++)
    {
        if (iter->second.size() <= 2)
            continue;
        int max = -1, sum = 0;
        for (int index : iter->second)
        {
            if (max == -1 || data[index].times > data[max].times)
                max = index;
            sum += data[index].times;
        }
        if ((sum >> 1) > K)
            result.push_back(gang(data[max].name, iter->second.size()));
    }

    std::cout << result.size() << std::endl;
    std::sort(result.begin(), result.end());
    for (gang g : result)
        std::cout << g.headName << " " << g.count << std::endl;
    return 0;
}
