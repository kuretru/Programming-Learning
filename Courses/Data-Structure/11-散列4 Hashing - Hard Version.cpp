#include <iostream>
#include <set>
#include <vector>

struct number
{
    int inDgree = 0;
    int index = -1;
    int value = -1;
    std::vector<int> edges;
    bool operator<(const number &y) const
    {
        if (inDgree != y.inDgree)
            return inDgree < y.inDgree;
        return value < y.value;
    }
};

int main()
{
    int N;
    std::cin >> N;
    std::vector<number> data(N);
    for (int i = 0; i < N; i++)
    {
        data[i].index = i;
        std::cin >> data[i].value;
    }
    for (int i = 0; i < N; i++)
    {
        if (data[i].value < 0)
            continue;
        for (int j = data[i].value % N; j != i; j = (j + 1) % N)
        {
            data[j].edges.push_back(i);
            data[i].inDgree++;
        }
    }

    std::set<number> queue;
    for (int i = 0; i < N; i++)
        if (data[i].value >= 0 && data[i].inDgree == 0)
            queue.insert(data[i]);
    while (!queue.empty())
    {
        number n = *queue.begin();
        queue.erase(queue.begin());
        for (auto iter = data[n.index].edges.begin(); iter != data[n.index].edges.end(); iter++)
            if (--data[*iter].inDgree == 0)
                queue.insert(data[*iter]);
        std::cout << n.value << (queue.empty() ? "\n" : " ");
    }
    return 0;
}
