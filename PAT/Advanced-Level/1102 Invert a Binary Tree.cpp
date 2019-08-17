#include <iostream>
#include <queue>
#include <vector>

struct node
{
    int parent = -1;
    int data = -1;
    int left = -1;
    int right = -1;
};

void print(std::vector<int> data)
{
    for (auto iter = data.begin(); iter != data.end(); iter++)
        std::cout << *iter << (iter != data.end() - 1 ? " " : "\n");
}

void levelOrder(std::vector<node> data, std::vector<int> &result, int head)
{
    std::queue<int> queue;
    queue.push(head);
    while (!queue.empty())
    {
        int front = queue.front();
        queue.pop();
        if (data[front].right != -1)
            queue.push(data[front].right);
        if (data[front].left != -1)
            queue.push(data[front].left);
        result.push_back(front);
    }
}

void inOrder(std::vector<node> &data, std::vector<int> &result, int head)
{
    if (head == -1)
        return;
    inOrder(data, result, data[head].right);
    result.push_back(head);
    inOrder(data, result, data[head].left);
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<node> data(N);
    for (int i = 0; i < N; i++)
    {
        char left, right;
        std::cin >> left >> right;
        data[i].data = i;
        if (left != '-')
        {
            data[i].left = left - '0';
            data[data[i].left].parent = i;
        }
        if (right != '-')
        {
            data[i].right = right - '0';
            data[data[i].right].parent = i;
        }
    }
    int head = -1;
    for (int i = 0; i < N; i++)
        if (data[i].parent == -1)
            head = i;
    std::vector<int> result;
    levelOrder(data, result, head);
    print(result);
    result.clear();
    inOrder(data, result, head);
    print(result);
    return 0;
}
