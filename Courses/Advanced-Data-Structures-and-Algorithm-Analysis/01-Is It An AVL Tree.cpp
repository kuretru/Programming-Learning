#include <iostream>

struct node
{
    int data = 0;
    node *left = NULL;
    node *right = NULL;
};

void build_tree(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node();
        head->data = data;
        return;
    }
    if (data < head->data)
        build_tree(head->left, data);
    else
        build_tree(head->right, data);
}

int depth(node *head)
{
    if (head == NULL)
        return 0;
    return std::max(depth(head->left), depth(head->right)) + 1;
}

bool is_avl_tree(node *head)
{
    if (!head)
        return true;
    int balanceFactor = depth(head->left) - depth(head->right);
    return abs(balanceFactor) <= 1 && is_avl_tree(head->left) && is_avl_tree(head->right);
}

int main()
{
    int K = 0, N = 0, tmp;
    std::cin >> K;
    while (K--)
    {
        node *root = NULL;
        std::cin >> N;
        while (N--)
        {
            std::cin >> tmp;
            build_tree(root, tmp);
        }
        std::cout << (is_avl_tree(root) ? "Yes" : "No") << std::endl;
    }
    return 0;
}
