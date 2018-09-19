#include <algorithm>
#include <iostream>
#include <queue>
const int empty = -19960203;
struct node
{
    int key = empty, index;
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
        return;
    }
    if (key < root->key)
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
    int N, key, max = 0;
    node *root = new node();
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> key;
        insert(root, key);
    }
    std::queue<node *> level;
    root->index = 1;
    level.push(root);
    while (!level.empty())
    {
        node *n = level.front();
        level.pop();
        if (n->left != NULL)
        {
            n->left->index = n->index * 2;
            level.push(n->left);
        }
        if (n->right != NULL)
        {
            n->right->index = n->index * 2 + 1;
            level.push(n->right);
        }
        if (n->index > max)
            max = n->index;
        std::cout << n->key << (level.empty() ? "\n" : " ");
    }
    std::cout << (max > N ? "NO" : "YES") << std::endl;
    return 0;
}
