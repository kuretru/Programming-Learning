#include <iostream>
#include <string>
#include <vector>

struct node
{
    std::string data = "";
    int left = 0;
    int right = 0;
};

void postOrder(std::vector<node> &data, int index)
{
    if (index == -1)
        return;
    std::cout << "(";
    if (data[index].left == -1 && data[index].right != -1)
    {
        std::cout << data[index].data;
        postOrder(data, data[index].right);
    }
    else
    {
        postOrder(data, data[index].left);
        postOrder(data, data[index].right);
        std::cout << data[index].data;
    }
    std::cout << ")";
}

int main()
{
    int N = 0;
    std::cin >> N;
    std::vector<node> data(N + 1);
    int head = (1 + N) * N / 2;
    for (int i = 1; i <= N; i++)
    {
        std::cin >> data[i].data >> data[i].left >> data[i].right;
        if (data[i].left != -1)
            head -= data[i].left;
        if (data[i].right != -1)
            head -= data[i].right;
    }
    postOrder(data, head);
    return 0;
}
