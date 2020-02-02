#include <iostream>
#include <map>

struct node
{
    int address = 0;
    char data = '\0';
    int next = 0;
    bool flag = false;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::map<int, node *> data;
    int x = 0, y = 0, count = 0;
    std::cin >> x >> y >> count;
    while (count--)
    {
        node *n = new node();
        std::cin >> n->address >> n->data >> n->next;
        data[n->address] = n;
    }
    while (x != -1)
    {
        data[x]->flag = true;
        x = data[x]->next;
    }
    while (y != -1)
    {
        if (data[y]->flag)
            break;
        y = data[y]->next;
    }
    if (y == -1)
        std::cout << -1 << std::endl;
    else
        printf("%05d\n", y);
    return 0;
}
