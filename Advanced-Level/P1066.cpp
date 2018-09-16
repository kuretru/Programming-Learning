#include <algorithm>
#include <iostream>
const int empty = -19960203;
struct node
{
    int key = empty;
    node *left = NULL, *right = NULL;
};
int height(node *root)
{
    if (root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return std::max(left, right) + 1;
}
void turnRight(node *root)
{
    node *a = root->right;
    node *b = root->left->right;
    std::swap(root->key, root->left->key);
    root->right = root->left;
    root->left = root->left->left;
    root->right->left = b;
    root->right->right = a;
}
void turnLeft(node *root)
{
    node *a = root->left;
    node *b = root->right->left;
    std::swap(root->key, root->right->key);
    root->left = root->right;
    root->right = root->right->right;
    root->left->right = b;
    root->left->left = a;
}
void insert(node *root, int key)
{
    if (root->key == empty)
    {
        root->key = key;
    }
    else if (key < root->key)
    {
        if (root->left == NULL)
            root->left = new node();
        insert(root->left, key);
    }
    else if (key > root->key)
    {
        if (root->right == NULL)
            root->right = new node();
        insert(root->right, key);
    }
    int left = height(root->left);
    int right = height(root->right);
    if (left - right == 2)
    {
        if (key > root->left->key)
            turnLeft(root->left);
        turnRight(root);
    }
    else if (left - right == -2)
    {
        if (key < root->right->key)
            turnRight(root->right);
        turnLeft(root);
    }
}
int main()
{
    int N, key;
    std::cin >> N;
    node *root = new node();
    while (N--)
    {
        std::cin >> key;
        insert(root, key);
    }
    std::cout << root->key << std::endl;
    return 0;
}
