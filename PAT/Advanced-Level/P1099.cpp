#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
struct node
{
    int left, key, right;
};
void preOrder(std::vector<node> &tree, std::vector<int> &data, int root, int &index)
{
    if (tree[root].left != -1)
        preOrder(tree, data, tree[root].left, index);
    tree[root].key = data[index++];
    if (tree[root].right != -1)
        preOrder(tree, data, tree[root].right, index);
}
int main()
{
    int N, index = 0;
    std::cin >> N;
    std::vector<node> tree(N);
    for (int i = 0; i < N; i++)
        std::cin >> tree[i].left >> tree[i].right;
    std::vector<int> data(N);
    for (int i = 0; i < N; i++)
        std::cin >> data[i];
    std::sort(data.begin(), data.end());
    preOrder(tree, data, 0, index);
    std::queue<node> result;
    result.push(tree[0]);
    while (!result.empty())
    {
        node n = result.front();
        result.pop();
        std::cout << n.key;
        if (n.left != -1)
            result.push(tree[n.left]);
        if (n.right != -1)
            result.push(tree[n.right]);
        std::cout << (result.empty() ? "\n" : " ");
    }
    return 0;
}
