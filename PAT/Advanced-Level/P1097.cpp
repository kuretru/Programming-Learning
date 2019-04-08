#include <iostream>
#include <map>
#include <vector>
struct node
{
    int address, key, next;
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::map<int, node> data;
    std::map<int, bool> exist;
    int head, count;
    std::cin >> head >> count;
    while (count--)
    {
        node n;
        std::cin >> n.address >> n.key >> n.next;
        data[n.address] = n;
    }
    std::vector<node> result[2];
    while (head != -1)
    {
        if (data.find(head) == data.end())
            break;
        node n = data[head];
        result[exist[abs(n.key)] ? 1 : 0].push_back(n);
        exist[abs(n.key)] = true;
        head = n.next;
    }
    for (int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < result[i].size(); j++)
        {
            printf("%05d %d ", result[i][j].address, result[i][j].key);
            if (j != result[i].size() - 1)
                printf("%05d\n", result[i][j + 1].address);
            else
                std::cout << -1 << std::endl;
        }
    }
    return 0;
}
