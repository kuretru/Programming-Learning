#include <iostream>
#include <map>
#include <string>
#include <vector>
struct node
{
    std::string address;
    int data;
    std::string next;
};
int main()
{
    std::string head;
    int count, K;
    std::cin >> head >> count >> K;

    std::map<std::string, node> memory;
    for (int i = 0; i < count; i++)
    {
        node n;
        std::cin >> n.address >> n.data >> n.next;
        memory[n.address] = n;
    }

    std::vector<node> data;
    std::string next = head;
    while (next != "-1")
    {
        data.push_back(memory[next]);
        next = memory[next].next;
    }

    for (int i = 0; i < data.size(); i += K)
    {
        for (int j = i, k = i + K - 1; j < k && k < data.size(); j++, k--)
        {
            node tmp = data[j];
            data[j] = data[k];
            data[k] = tmp;
        }
    }

    bool prited = false;
    for (auto iter = data.begin(); iter != data.end(); iter++)
    {
        if (prited)
            std::cout << iter->address << std::endl;
        else
            prited = true;
        std::cout << iter->address << " " << iter->data << " ";
    }
    std::cout << "-1" << std::endl;
    return 0;
}
