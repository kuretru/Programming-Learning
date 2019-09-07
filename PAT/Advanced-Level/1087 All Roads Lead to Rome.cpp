#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

const std::string end = "ROM";

struct city
{
    std::string name = "";
    int happiness = 0;
    std::vector<int> edges;
    bool visited = false;
    city(int n)
    {
        edges.resize(n, -1);
    }
};

struct plan
{
    int cost = 0;
    int happiness = 0;
    std::vector<int> path;
    bool operator<(const plan &y) const
    {
        if (cost != y.cost)
            return cost < y.cost;
        if (happiness != y.happiness)
            return happiness > y.happiness;
        return path.size() <= y.path.size();
    }
};

void dfs(std::vector<city> &data, std::set<plan> &result, plan &record, int start, int end)
{
    record.happiness += data[start].happiness;
    record.path.push_back(start);
    data[start].visited = true;
    if (start == end)
    {
        if (result.empty() || record.cost <= result.begin()->cost)
        {
            if (!result.empty() && record.cost < result.begin()->cost)
                result.clear();
            result.insert(record);
        }
    }
    else
    {
        for (int i = 1; i < data[start].edges.size(); i++)
        {
            if (data[start].edges[i] < 0 || data[i].visited)
                continue;
            record.cost += data[start].edges[i];
            dfs(data, result, record, i, end);
            record.cost -= data[start].edges[i];
        }
    }
    record.happiness -= data[start].happiness;
    record.path.pop_back();
    data[start].visited = false;
}

int main()
{
    int N = 0, K = 0;
    std::cin >> N >> K;
    std::vector<city> data(N, city(N));
    std::map<std::string, int> map;
    std::cin >> data[0].name;
    map[data[0].name] = 0;
    for (int i = 1; i < N; i++)
    {
        std::cin >> data[i].name >> data[i].happiness;
        map[data[i].name] = i;
    }
    while (K--)
    {
        std::string city1 = "", city2 = "";
        int cost = 0;
        std::cin >> city1 >> city2 >> cost;
        data[map[city1]].edges[map[city2]] = data[map[city2]].edges[map[city1]] = cost;
    }
    std::set<plan> result;
    plan record;
    dfs(data, result, record, 0, map[end]);
    record = *result.begin();
    printf("%d %d %d %d\n", (int)result.size(), record.cost, record.happiness,
           (int)(record.happiness * 1.0 / (record.path.size() - 1)));
    for (auto iter = record.path.begin(); iter != record.path.end(); iter++)
        std::cout << data[*iter].name << (iter != record.path.end() - 1 ? "->" : "\n");
    return 0;
}
