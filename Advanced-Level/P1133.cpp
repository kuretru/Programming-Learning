#include <iostream>
#include <map>
#include <vector>
struct node
{
    int address, data, next;
};
int main()
{
    int head, N, K;
    std::cin >> head >> N >> K;
    std::map<int, node *> data;
    while (N--)
    {
        node *n = new node();
        std::cin >> n->address >> n->data >> n->next;
        data[n->address] = n;
    }
    std::vector<node *> list[3];
    while (head != -1)
    {
        node *n = data[head];
        list[n->data < 0 ? 0 : (n->data <= K) ? 1 : 2].push_back(n);
        head = n->next;
    }
    list[0].insert(list[0].end(), list[1].begin(), list[1].end());
    list[0].insert(list[0].end(), list[2].begin(), list[2].end());
    for (auto iter = list[0].begin(); iter != list[0].end(); iter++)
    {
        if (iter != list[0].begin())
            printf("%05d\n", (*iter)->address);
        printf("%05d %d ", (*iter)->address, (*iter)->data);
    }
    std::cout << -1 << std::endl;
    return 0;
}
