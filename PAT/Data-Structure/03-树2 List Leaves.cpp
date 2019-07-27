#include <iostream>
#include <queue>
#include <vector>
struct node
{
    int data;
    int left;
    int right;
};
std::vector<node> input(int N)
{
    std::vector<node> data;
    for (int i = 0; i < N; i++)
    {
        char left, right;
        std::cin >> left >> right;
        node n;
        n.data = i;
        n.left = left == '-' ? -1 : left - '0';
        n.right = right == '-' ? -1 : right - '0';
        data.push_back(n);
    }
    return data;
}
int findHead(std::vector<node> data)
{
    std::vector<bool> flag(data.size(), false);
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].left != -1)
            flag[data[i].left] = true;
        if (data[i].right != -1)
            flag[data[i].right] = true;
    }
    for (int i = 0; i < data.size(); i++)
        if (!flag[i])
            return i;
    return -1;
}
int main()
{
    int N;
    std::cin >> N;
    std::vector<node> data = input(N);
    int head = findHead(data);
    std::vector<int> result;
    std::queue<node> queue;
    queue.push(data[head]);
    while (!queue.empty())
    {
        node n = queue.front();
        queue.pop();
        if (n.left != -1)
            queue.push(data[n.left]);
        if (n.right != -1)
            queue.push(data[n.right]);
        if (n.left == -1 && n.right == -1)
            result.push_back(n.data);
    }
    for (auto iter = result.begin(); iter != result.end(); iter++)
        std::cout << *iter << (iter != result.end() - 1 ? " " : "\n");
    return 0;
}
