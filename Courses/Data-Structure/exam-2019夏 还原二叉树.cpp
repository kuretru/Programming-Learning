#include <iostream>
#include <string>

struct node
{
    char data;
    node *left = NULL;
    node *right = NULL;
};

std::string pre, in;

void buildTree(node *&head, int preLeft, int preRight, int inLeft, int inRight)
{
    if (preLeft > preRight)
        return;
    char key = pre[preLeft];
    if (!head)
        head = new node();
    head->data = key;
    int index = in.find(key);
    int leftCount = index - inLeft;
    buildTree(head->left, preLeft + 1, preLeft + leftCount, inLeft, index - 1);
    buildTree(head->right, preLeft + leftCount + 1, preRight, index + 1, inRight);
}

int treeHeight(node *head)
{
    if (!head)
        return 0;
    return std::max(treeHeight(head->left), treeHeight(head->right)) + 1;
}

int main()
{
    int N;
    std::cin >> N >> pre >> in;
    node *head = NULL;
    buildTree(head, 0, N - 1, 0, N - 1);
    std::cout << treeHeight(head) << std::endl;
    return 0;
}
