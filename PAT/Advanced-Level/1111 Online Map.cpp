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

bool compare_distance(street &x, street &y);
bool compare_time(street &x, street &y);
typedef bool (*compare_interface)(street &x, street &y);
result dijkstra(std::vector<std::vector<street>> &data, int source, int destination, compare_interface compare);
void print_path(std::vector<int> path);

int main()
{
    int N = 0, M = 0, source = 0, destination = 0;
    std::cin >> N >> M;
    std::vector<std::vector<street>> data(N, std::vector<street>(N));
    while (M--)
    {
        int v1 = 0, v2 = 0, oneWay = 0;
        std::cin >> v1 >> v2 >> oneWay;
        std::cin >> data[v1][v2].length >> data[v1][v2].time;
        if (!oneWay)
            data[v2][v1] = data[v1][v2];
    }
    std::cin >> source >> destination;
    result result_distance = dijkstra(data, source, destination, compare_distance);
    result result_time = dijkstra(data, source, destination, compare_time);
    if (result_distance.path == result_time.path)
    {
        std::cout << "Distance = " << result_distance.distance << "; Time = " << result_time.time << ": ";
        print_path(result_distance.path);
    }
    else
    {
        std::cout << "Distance = " << result_distance.distance << ": ";
        print_path(result_distance.path);
        std::cout << "Time = " << result_time.time << ": ";
        print_path(result_time.path);
    }
    return 0;
}

result dijkstra(std::vector<std::vector<street>> &data, int source, int destination, compare_interface compare)
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
    std::vector<int> path;
    for (int head = destination; head != -1; head = D[head].path)
        path.push_back(head);
    result r;
    r.distance = D[destination].params.length;
    r.time = D[destination].params.time;
    r.path = std::vector<int>(path.rbegin(), path.rend());
    return r;
}

bool compare_distance(street &x, street &y)
{
    if (x.length != y.length)
        return x.length < y.length;
    return x.time < y.time;
}

bool compare_time(street &x, street &y)
{
    if (x.time != y.time)
        return x.time < y.time;
    return x.nodes < y.nodes;
}

void print_path(std::vector<int> path)
{
    for (auto iter = path.begin(); iter != path.end(); iter++)
        std::cout << *iter << (iter != path.end() - 1 ? " -> " : "\n");
}
