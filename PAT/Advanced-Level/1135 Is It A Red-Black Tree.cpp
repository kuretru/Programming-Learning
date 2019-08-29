#include <iostream>

struct node
{
    int value = 0;
    bool black = true;
    node *left = NULL;
    node *right = NULL;
};

void buildTree(node *&head, int value)
{
    if (head == NULL)
    {
        head = new node();
        head->value = abs(value);
        head->black = value >= 0;
        return;
    }
    if (abs(value) < head->value)
        buildTree(head->left, value);
    else
        buildTree(head->right, value);
}

int isRedBlackTree(node *head, bool mustBlack, int blackCount)
{
    if (head == NULL)
        return blackCount;
    if (mustBlack && !head->black)
        return -1;
    if (head->black)
        blackCount++;
    int leftBlackCount = isRedBlackTree(head->left, !head->black, blackCount);
    int rightBlackCount = isRedBlackTree(head->right, !head->black, blackCount);
    if (leftBlackCount == -1 || rightBlackCount == -1)
        return -1;
    if (leftBlackCount != rightBlackCount)
        return -1;
    return leftBlackCount;
}

int main()
{
    int K = 0;
    std::cin >> K;
    while (K--)
    {
        int count = 0, value = 0;
        std::cin >> count;
        node *head = NULL;
        while (count--)
        {
            std::cin >> value;
            buildTree(head, value);
        }
        bool result = isRedBlackTree(head, true, 0) != -1;
        std::cout << (result ? "Yes" : "No") << std::endl;
    }
    return 0;
}
