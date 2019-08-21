#include <iostream>
#include <map>

struct node
{
    int data = INT32_MAX;
    node *left = NULL;
    node *right = NULL;
};

void insert(node *head, int key, std::map<int, int> &result, int level)
{
    if (head->data == INT32_MAX)
    {
        head->data = key;
        result[level]++;
    }
    else if (key <= head->data)
    {
        if (head->left == NULL)
            head->left = new node();
        insert(head->left, key, result, level + 1);
    }
    else if (key > head->data)
    {
        if (head->right == NULL)
            head->right = new node();
        insert(head->right, key, result, level + 1);
    }
}

int main()
{
    int N, key;
    std::cin >> N;
    node *head = new node();
    std::map<int, int> result;
    while (N--)
    {
        std::cin >> key;
        insert(head, key, result, 0);
    }
    int x = result.rbegin()->second;
    int y = result.size() == 1 ? 0 : (++result.rbegin())->second;
    std::cout << x << " + " << y << " = " << x + y;
    return 0;
}
