#include <algorithm>
#include <iostream>
#include <vector>
struct node
{
    int weight, index;
    std::vector<node *> leaves;
};
bool cmp(const node *x, const node *y)
{
    if (x->weight != y->weight)
        return x->weight > y->weight;
    return x->index > y->index;
}
std::vector<node> data;
int S;
void DST(node *root, int sum, std::vector<int> sequence)
{
    sum += root->weight;
    if (sum > S)
        return;
    sequence.push_back(root->weight);
    std::vector<node *> &leaves = root->leaves;
    if (leaves.empty() && sum == S)
    {
        for (auto iter = sequence.begin(); iter != sequence.end(); iter++)
        {
            if (iter != sequence.begin())
                std::cout << " ";
            std::cout << *iter;
        }
        std::cout << std::endl;
    }
    for (auto iter = leaves.begin(); iter != leaves.end(); iter++)
        DST(*iter, sum, sequence);
}
int main()
{
    int N, M, id, count, key;
    std::cin >> N >> M >> S;
    data.resize(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> data[i].weight;
        data[i].index = i;
    }
    for (int i = 0; i < M; i++)
    {
        std::cin >> id >> count;
        for (int j = 0; j < count; j++)
        {
            std::cin >> key;
            data[id].leaves.push_back(&data[key]);
        }
        sort(data[id].leaves.begin(), data[id].leaves.end(), cmp);
    }
    std::vector<int> result;
    DST(&data[0], 0, result);
    return 0;
}
