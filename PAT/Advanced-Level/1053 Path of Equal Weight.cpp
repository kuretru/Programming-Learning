#include <algorithm>
#include <iostream>
#include <vector>

struct node
{
    int index = 0;
    int weight = 0;
    std::vector<node *> leaves;
};

bool cmp(const node *x, const node *y)
{
    if (x->weight != y->weight)
        return x->weight > y->weight;
    return x->index > y->index;
}

void DST(std::vector<node> &data, std::vector<int> sequence, node *root, int sum, int S)
{
    sum += root->weight;
    if (sum > S)
        return;
    sequence.push_back(root->weight);
    if (root->leaves.empty() && sum == S)
    {
        for (auto iter = sequence.begin(); iter != sequence.end(); iter++)
            std::cout << *iter << (iter != sequence.end() - 1 ? " " : "\n");
    }
    for (auto iter = root->leaves.begin(); iter != root->leaves.end(); iter++)
        DST(data, sequence, *iter, sum, S);
}

int main()
{
    int N = 0, M = 0, S = 0;
    std::cin >> N >> M >> S;
    std::vector<node> data(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> data[i].weight;
        data[i].index = i;
    }
    for (int i = 0; i < M; i++)
    {
        int id = 0, count = 0, key = 0;
        std::cin >> id >> count;
        for (int j = 0; j < count; j++)
        {
            std::cin >> key;
            data[id].leaves.push_back(&data[key]);
        }
        sort(data[id].leaves.begin(), data[id].leaves.end(), cmp);
    }
    std::vector<int> result;
    DST(data, std::vector<int>(), &data[0], 0, S);
    return 0;
}
