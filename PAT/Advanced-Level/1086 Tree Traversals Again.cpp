#include <iostream>
#include <stack>
#include <string>
#include <vector>

struct node
{
    int value = 0;
    node *left = NULL;
    node *right = NULL;
};

void postorder(node *head, std::vector<int> &result)
{
    if (!head)
        return;
    postorder(head->left, result);
    postorder(head->right, result);
    result.push_back(head->value);
}

int main()
{
    int N = 0;
    std::cin >> N;
    N <<= 1;
    node *head = new node();
    node *ptr = head;
    std::stack<node *> stack;
    while (N--)
    {
        std::string command = "";
        std::cin >> command;
        if (command == "Push")
        {
            node *n = new node();
            std::cin >> n->value;
            if (ptr->left == NULL)
                ptr->left = n;
            else
                ptr->right = n;
            ptr = n;
            stack.push(n);
        }
        else
        {
            ptr = stack.top();
            stack.pop();
        }
    }
    std::vector<int> result;
    postorder(head->left, result);
    for (auto iter = result.begin(); iter != result.end(); iter++)
        std::cout << *iter << (iter != result.end() - 1 ? " " : "\n");
    return 0;
}
