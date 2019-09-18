#include <iostream>
struct node
{
    int value = 0;
    node *left = NULL;
    node *right = NULL;
};
void insert(node *head, int value)
{
    if (!head->value)
        head->value = value;
    else if (value < head->value)
    {
        if (!head->left)
            head->left = new node();
        insert(head->left, value);
    }
    else
    {
        if (!head->right)
            head->right = new node();
        insert(head->right, value);
    }
}
void buildTree(node *head, int N)
{
    int value;
    for (int i = 0; i < N; i++)
    {
        std::cin >> value;
        insert(head, value);
    }
}
bool compare(node *x, node *y)
{
    if (!x && !y)
        return true;
    if (!x || !y)
        return false;
    if (x->value != y->value)
        return false;
    return compare(x->left, y->left) & compare(x->right, y->right);
}
int main()
{
    int N, L;
    while (std::cin >> N)
    {
        if (!N)
            break;
        std::cin >> L;
        node raw;
        buildTree(&raw, N);
        while (L--)
        {
            node data;
            buildTree(&data, N);
            std::cout << (compare(&raw, &data) ? "Yes" : "No") << std::endl;
        }
    }
    return 0;
}
