#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
struct node
{
    int address;
    int data;
    int next;
    int group;
    bool operator<(const node n) const
    {
        return this->group < n.group;
    }
};
int main()
{
    std::map<int, node> linkList;
    std::vector<node> result;
    int head, N, K;
    std::cin >> head >> N >> K;
    for (int i = 0; i < N; i++)
    {
        node n;
        std::cin >> n.address >> n.data >> n.next;
        if (n.data < 0)
            n.group = -1;
        else if (n.data <= K)
            n.group = 0;
        else
            n.group = 1;
        linkList[n.address] = n;
    }
    int next = head;
    while (next != -1)
    {
        result.push_back(linkList[next]);
        next = linkList[next].next;
    }
    std::stable_sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
    {
        printf("%05d %d ", result[i].address, result[i].data);
        if (i < result.size() - 1)
            printf("%05d\n", result[i + 1].address);
    }
    std::cout << "-1" << std::endl;
    return 0;
}
