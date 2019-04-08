#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
struct node
{
    int address;
    int data;
    int next;
};
int main()
{
    int head;
    std::map<int, node> data;
    std::vector<node> result;
    int N, K;
    std::cin >> head >> N >> K;
    for (int i = 0; i < N; i++)
    {
        node n;
        std::cin >> n.address >> n.data >> n.next;
        data[n.address] = n;
    }
    int next = head;
    while (next != -1)
    {
        result.push_back(data[next]);
        next = data[next].next;
    }
    for (int i = 0; i <= result.size() - K; i += K)
        reverse(result.begin() + i, result.begin() + i + K);
    for (int i = 0; i < result.size(); i++)
    {
        printf("%05d %d ", result[i].address, result[i].data);
        if (i < result.size() - 1)
            printf("%05d\n", result[i + 1].address);
    }
    std::cout << "-1" << std::endl;
    return 0;
}
