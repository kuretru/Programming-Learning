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
    int L1 = 0, L2 = 0, N = 0;
    std::cin >> L1 >> L2 >> N;
    std::map<int, node> all;
    for (int i = 0; i < N; i++)
    {
        node n;
        std::cin >> n.address >> n.data >> n.next;
        all[n.address] = n;
    }
    std::vector<node> data1, data2;
    int head = L1;
    while (head != -1)
    {
        data1.push_back(all[head]);
        head = all[head].next;
    }
    head = L2;
    while (head != -1)
    {
        data2.push_back(all[head]);
        head = all[head].next;
    }
    std::vector<node> &small = data1.size() < data2.size() ? data1 : data2;
    std::vector<node> &big = data1.size() < data2.size() ? data2 : data1;
    std::reverse(small.begin(), small.end());
    std::vector<node> result;
    int i = 0, j = 0, k = 0;
    while (i < small.size())
    {
        result.push_back(big[j++]);
        result.push_back(big[j++]);
        result.push_back(small[i++]);
    }
    while (j < big.size())
        result.push_back(big[j++]);
    for (auto iter = result.begin(); iter != result.end(); iter++)
    {
        if (iter != result.begin())
            printf("%05d\n", iter->address);
        printf("%05d %d ", iter->address, iter->data);
    }
    std::cout << -1 << std::endl;
    return 0;
}
