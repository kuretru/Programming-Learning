#include <iostream>
#include <map>
#include <set>
#include <vector>

struct node
{
    int address = 0;
    int key = 0;
    int next = 0;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::map<int, node> data;
    std::set<int> exist;
    int head = 0, count = 0;
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
        result[exist.count(abs(n.key)) ? 1 : 0].push_back(n);
        exist.insert(abs(n.key));
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
                printf("-1\n");
        }
    }
    return 0;
}
