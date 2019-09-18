#include <iostream>
#include <vector>
struct node
{
    char data;
    int left;
    int right;
};
std::vector<node> input(int N)
{
    std::vector<node> data;
    while (N--)
    {
        node n;
        char left, right;
        std::cin >> n.data >> left >> right;
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
bool check(std::vector<node> &T1, std::vector<node> &T2, int head1, int head2)
{
    if (head1 == -1 && head2 == -1)
        return true;
    if (head1 == -1 || head2 == -1)
        return false;
    node node1 = T1[head1], node2 = T2[head2];
    if (node1.data != node2.data)
        return false;
    return (check(T1, T2, node1.left, node2.left) && check(T1, T2, node1.right, node2.right)) ||
           (check(T1, T2, node1.left, node2.right) && check(T1, T2, node1.right, node2.left));
}
int main()
{
    int N, M;
    std::cin >> N;
    std::vector<node> T1 = input(N);
    std::cin >> M;
    std::vector<node> T2 = input(M);
    int head1 = findHead(T1);
    int head2 = findHead(T2);
    std::cout << (check(T1, T2, head1, head2) ? "Yes" : "No") << std::endl;
    return 0;
}
