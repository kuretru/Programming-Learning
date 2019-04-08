#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
struct node
{
    int address, value, next;
    bool operator<(const node &y)
    {
        return value < y.value;
    }
};
int main()
{
    int N, head;
    std::cin >> N >> head;
    std::map<int, node> memory;
    while (N--)
    {
        node n;
        std::cin >> n.address >> n.value >> n.next;
        memory[n.address] = n;
    }
    std::vector<node> list;
    while (memory.find(head) != memory.end())
    {
        list.push_back(memory[head]);
        head = memory[head].next;
    }
    sort(list.begin(), list.end());
    std::cout << list.size() << " ";
    for (auto iter = list.begin(); iter != list.end(); iter++)
        printf("%05d\n%05d %d ", iter->address, iter->address, iter->value);
    std::cout << -1 << std::endl;
    return 0;
}
