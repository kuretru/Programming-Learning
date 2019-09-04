#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

struct edge
{
    int id = 0;
    int line = 0;
    edge(int id, int line)
    {
        this->id = id;
        this->line = line;
    }
};

struct result
{
    int stops = 0;
    int transfers = 0;
    std::vector<edge> path;
    std::set<int> visited;
    bool operator<(const result &y) const
    {
        if (stops != y.stops)
            return stops < y.stops;
        return transfers < y.transfers;
    }
};

void DFS(std::unordered_map<int, std::vector<edge>> &data, edge start, int end, result &min, result &plan)
{
    if (min.stops > 0 && plan.stops > min.stops) // 剪枝，改为传递引用参数后，不剪也没问题
        return;
    int oldTransfers = plan.transfers;
    plan.stops++;
    if (plan.path.empty() || plan.path.back().line != start.line)
        plan.transfers++;
    plan.path.push_back(start);
    plan.visited.insert(start.id);
    if (start.id == end)
    {
        if (min.stops == 0 || plan < min)
            min = plan;
        goto backtrack;
    }
    for (edge e : data[start.id])
        if (!plan.visited.count(e.id))
            DFS(data, e, end, min, plan);
backtrack:
    plan.stops--;
    plan.transfers = oldTransfers;
    plan.path.pop_back();
    plan.visited.erase(start.id);
}

int main()
{
    std::ios::sync_with_stdio(false);
    int N = 0, K = 0;
    std::cin >> N;
    std::unordered_map<int, std::vector<edge>> data;
    for (int line = 1; line <= N; line++)
    {
        int count = 0, first = 0, second = 0;
        std::cin >> count >> first;
        for (int j = 1; j < count; j++)
        {
            std::cin >> second;
            data[first].push_back(edge(second, line));
            data[second].push_back(edge(first, line));
            first = second;
        }
    }
    std::cin >> K;
    while (K--)
    {
        int start = 0, end = 0;
        std::cin >> start >> end;
        result min, plan;
        DFS(data, edge(start, 0), end, min, plan);
        std::vector<edge> &path = min.path;
        path[0].line = path[1].line;
        printf("%d\n", min.stops - 1);
        for (unsigned i = 0; i < path.size(); i++)
        {
            if (i == 0 || path[i - 1].line != path[i].line)
                printf("Take Line#%d from %04d to ", path[i].line, i == 0 ? path[0].id : path[i - 1].id);
            if (i == path.size() - 1 || path[i + 1].line != path[i].line)
                printf("%04d.\n", path[i].id);
        }
    }
    return 0;
}
