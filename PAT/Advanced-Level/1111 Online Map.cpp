#include <iostream>
#include <vector>

struct street
{
    int length = -1;
    int time = -1;
    int nodes = 0;
    street operator+(const street &y)
    {
        street s;
        s.length = length + y.length;
        s.time = time + y.time;
        s.nodes = nodes + 1;
        return s;
    }
};

struct auxiliary
{
    bool used = false;
    int path = -1;
    struct street params;
};

struct result
{
    int distance = -1;
    int time = -1;
    std::vector<int> path;
};

bool compareDistance(street &x, street &y);
bool compareTime(street &x, street &y);
typedef bool (*compareInterface)(street &x, street &y);
result dijkstra(std::vector<std::vector<street>> &data, int source, int destination, compareInterface compare);
void printPath(std::vector<int> path);

int main()
{
    int N, M, source, destination;
    std::cin >> N >> M;
    std::vector<std::vector<street>> data(N, std::vector<street>(N));
    while (M--)
    {
        int v1, v2, oneWay;
        std::cin >> v1 >> v2 >> oneWay;
        std::cin >> data[v1][v2].length >> data[v1][v2].time;
        if (!oneWay)
            data[v2][v1] = data[v1][v2];
    }
    std::cin >> source >> destination;
    result rDistance = dijkstra(data, source, destination, compareDistance);
    result rTime = dijkstra(data, source, destination, compareTime);
    if (rDistance.path == rTime.path)
    {
        std::cout << "Distance = " << rDistance.distance << "; Time = " << rTime.time << ": ";
        printPath(rDistance.path);
    }
    else
    {
        std::cout << "Distance = " << rDistance.distance << ": ";
        printPath(rDistance.path);
        std::cout << "Time = " << rTime.time << ": ";
        printPath(rTime.path);
    }
    return 0;
}

result dijkstra(std::vector<std::vector<street>> &data, int source, int destination, compareInterface compare)
{
    std::vector<auxiliary> D(data.size());
    for (size_t i = 0; i < D.size(); i++)
    {
        if (data[source][i].length == -1)
            continue;
        D[i].path = source;
        D[i].params = data[source][i];
        D[i].params.nodes++;
    }
    D[source].used = true;
    for (size_t i = 0; i < D.size(); i++)
    {
        int min = -1;
        for (size_t j = 0; j < D.size(); j++)
        {
            if (D[j].used || D[j].params.length == -1)
                continue;
            if (min == -1 || compare(D[j].params, D[min].params))
                min = j;
        }
        if (min == -1)
            break;
        D[min].used = true;
        for (size_t j = 0; j < D.size(); j++)
        {
            if (D[j].used || data[min][j].length == -1)
                continue;
            street s = D[min].params + data[min][j];
            if (D[j].params.length == -1 || compare(s, D[j].params))
            {
                D[j].path = min;
                D[j].params = s;
                D[j].params.nodes++;
            }
        }
    }
    result r;
    r.distance = D[destination].params.length;
    r.time = D[destination].params.time;
    std::vector<int> path;
    for (int head = destination; head != -1; head = D[head].path)
        path.push_back(head);
    r.path = std::vector<int>(path.rbegin(), path.rend());
    return r;
}

bool compareDistance(street &x, street &y)
{
    if (x.length != y.length)
        return x.length < y.length;
    return x.time < y.time;
}

bool compareTime(street &x, street &y)
{
    if (x.time != y.time)
        return x.time < y.time;
    return x.nodes < y.nodes;
}

void printPath(std::vector<int> path)
{
    for (auto iter = path.begin(); iter != path.end(); iter++)
        std::cout << *iter << (iter != path.end() - 1 ? " -> " : "\n");
}
