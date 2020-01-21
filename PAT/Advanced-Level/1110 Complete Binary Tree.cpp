#include <iostream>
#include <string>
#include <vector>

struct node
{
    int index;
    node *left = NULL, *right = NULL, *parent = NULL;
};

int N;
node *end = NULL;

void depth(node *n, int index, int &max)
{
    if (index > max)
        max = index;
    if (n->left != NULL)
        depth(n->left, index * 2, max);
    if (n->right != NULL)
        depth(n->right, index * 2 + 1, max);
    if (index == N)
        end = n;
}

int main()
{
    std::cin >> N;
    std::vector<node> data(N);
    node *root = NULL;
    for (int i = 0; i < N; i++)
    {
        data[i].index = i;
        std::string left, right;
        std::cin >> left >> right;
        int index = -1;
        if (left != "-")
        {
            index = std::stoi(left);
            data[i].left = &data[index];
            data[index].parent = &data[i];
        }
        if (right != "-")
        {
            index = std::stoi(right);
            data[i].right = &data[index];
            data[index].parent = &data[i];
        }
        if ((root == NULL && index != -1) || N == 1)
            root = &data[i];
    }
    while (root->parent != NULL)
        root = root->parent;
    int result = 0;
    depth(root, 1, result);
    if (result == N)
        std::cout << "YES " << end->index << std::endl;
    else
        std::cout << "NO " << root->index << std::endl;
    return 0;
}
