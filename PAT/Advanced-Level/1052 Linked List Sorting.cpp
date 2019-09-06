#include <iostream>
#include <map>
#include <set>
#include <vector>

struct node
{
    int address = 0;
    int value = 0;
    int next = 0;
    bool operator<(const node &y) const
    {
        return value < y.value;
    }
};

int main()
{
    int N = 0, head = 0;
    std::cin >> N >> head;
    std::map<int, node> memory;
    while (N--)
    {
        node n;
        std::cin >> n.address >> n.value >> n.next;
        memory[n.address] = n;
    }
    std::set<node> list;
    while (memory.count(head))
    {
        list.insert(memory[head]);
        head = memory[head].next;
    }
    std::cout << list.size() << " ";
    for (auto iter = list.begin(); iter != list.end(); iter++)
        printf("%05d\n%05d %d ", iter->address, iter->address, iter->value);
    std::cout << -1 << std::endl;
    return 0;
}
