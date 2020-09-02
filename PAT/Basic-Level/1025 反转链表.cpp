#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

struct node
{
    int address = 0;
    int data = 0;
    int next = 0;
};

int main()
{
    std::map<int, node> nodes;
    std::vector<node> list;
    int head = 0, N = 0, K = 0;
    std::cin >> head >> N >> K;
    while (N--)
    {
        node n;
        std::cin >> n.address >> n.data >> n.next;
        nodes[n.address] = n;
    }
    while (head != -1)
    {
        if (nodes.find(head) == nodes.end())
            break;
        list.push_back(nodes[head]);
        head = list.back().next;
    }
    for (int i = 0; i <= list.size() - K; i += K)
        std::reverse(list.begin() + i, list.begin() + i + K);
    for (int i = 0; i < list.size(); i++)
    {
        printf("%05d %d ", list[i].address, list[i].data);
        if (i < list.size() - 1)
            printf("%05d\n", list[i + 1].address);
    }
    std::cout << "-1" << std::endl;
    return 0;
}
