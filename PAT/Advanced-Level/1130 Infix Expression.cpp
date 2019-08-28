#include <iostream>
#include <string>
#include <vector>

struct node
{
    std::string text = "";
    int left = -1;
    int right = -1;
};

void inorder_travel(std::vector<node> &data, int head, int root)
{
    if (root == -1)
        return;
    if (head != root && (data[root].left != -1 || data[root].right != -1))
        std::cout << "(";
    inorder_travel(data, head, data[root].left);
    std::cout << data[root].text;
    inorder_travel(data, head, data[root].right);
    if (head != root && (data[root].left != -1 || data[root].right != -1))
        std::cout << ")";
}

int main()
{
    int N = 0;
    std::cin >> N;
    std::vector<node> data(N + 1);
    std::vector<bool> head_flags(N + 1, true);
    for (int i = 1; i <= N; i++)
    {
        std::cin >> data[i].text >> data[i].left >> data[i].right;
        if (data[i].left != -1)
            head_flags[data[i].left] = false;
        if (data[i].right != -1)
            head_flags[data[i].right] = false;
    }
    int head = 0;
    for (int i = 1; i <= N; i++)
        if (head_flags[i])
            head = i;
    inorder_travel(data, head, head);
    std::cout << std::endl;
    return 0;
}
