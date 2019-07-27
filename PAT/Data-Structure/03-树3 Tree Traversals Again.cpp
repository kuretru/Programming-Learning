#include <iostream>
#include <stack>
#include <string>
#include <vector>
struct node
{
    int data;
    node *left = NULL;
    node *right = NULL;
};
void postOrder(std::vector<int> &result, node *head)
{
    if (!head)
        return;
    postOrder(result, head->left);
    postOrder(result, head->right);
    result.push_back(head->data);
}
int main()
{
    int N;
    std::cin >> N;
    N <<= 1;
    std::stack<node *> stack;
    node head;
    node *top = &head;
    while (N--)
    {
        std::string key;
        std::cin >> key;
        if (key == "Push")
        {
            node *n = new node();
            std::cin >> n->data;
            if (top->left == NULL)
                top->left = n;
            else
                top->right = n;
            top = n;
            stack.push(n);
        }
        else
        {
            top = stack.top();
            stack.pop();
        }
    }
    std::vector<int> result;
    postOrder(result, head.left);
    for (auto iter = result.begin(); iter != result.end(); iter++)
        std::cout << *iter << (iter != result.end() - 1 ? " " : "\n");
    return 0;
}
