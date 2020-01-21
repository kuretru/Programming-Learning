#include <iostream>
#include <vector>

struct node
{
    int value = 0;
    node *left = NULL;
    node *right = NULL;
};

void buildTree(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node();
        root->value = data;
    }
    else if (data < root->value)
        buildTree(root->left, data);
    else
        buildTree(root->right, data);
}

// 0*->先序遍历 1*->后序遍历 *0->正常树 *1->镜像树
void travel(node *root, std::vector<int> &data, int flag)
{
    if (root == NULL)
        return;
    if ((flag & 0x2) == 0x0)
        data.push_back(root->value);
    if ((flag & 0x1) == 0x0)
    {
        travel(root->left, data, flag);
        travel(root->right, data, flag);
    }
    else if ((flag & 0x1) == 0x1)
    {
        travel(root->right, data, flag);
        travel(root->left, data, flag);
    }
    if ((flag & 0x2) == 0x2)
        data.push_back(root->value);
}

int main()
{
    int N = 0;
    std::cin >> N;
    std::vector<int> data(N);
    for (int i = 0; i < N; i++)
        std::cin >> data[i];
    node *root = NULL;
    for (int i : data)
        buildTree(root, i);
    std::vector<int> bst, postorder;
    int flag = 0x0;
    travel(root, bst, flag);
    if (bst != data)
    {
        bst.clear();
        flag |= 0x1;
        travel(root, bst, flag);
    }
    if (bst == data)
    {
        std::cout << "YES" << std::endl;
        flag |= 0x2;
        travel(root, postorder, flag);
        for (auto iter = postorder.begin(); iter != postorder.end(); iter++)
            std::cout << *iter << (iter != postorder.end() - 1 ? " " : "\n");
        return 0;
    }
    std::cout << "NO" << std::endl;
    return 0;
}
