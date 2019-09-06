#include <iostream>

struct node
{
    int data;
    node *left = NULL;
    node *right = NULL;
};

void turnLeft(node *&head)
{
    node *A = head;
    node *B = head->right;
    A->right = B->left;
    B->left = A;
    head = B;
}

void turnRight(node *&head)
{
    node *A = head;
    node *B = head->left;
    A->left = B->right;
    B->right = A;
    head = B;
}

int height(node *head)
{
    if (!head)
        return 0;
    int left = height(head->left);
    int right = height(head->right);
    return std::max(left, right) + 1;
}

void insert(node *&head, int data)
{
    if (!head)
    {
        head = new node();
        head->data = data;
        return;
    }
    if (data < head->data)
        insert(head->left, data);
    else
        insert(head->right, data);

    int left = height(head->left);
    int right = height(head->right);
    if (left - right == 2)
    {
        if (data > head->left->data)
            turnLeft(head->left);
        turnRight(head);
    }
    else if (left - right == -2)
    {
        if (data < head->right->data)
            turnRight(head->right);
        turnLeft(head);
    }
}

int main()
{
    int N, key;
    std::cin >> N;
    node *head = NULL;
    for (int i = 0; i < N; i++)
    {
        std::cin >> key;
        insert(head, key);
    }
    std::cout << head->data << std::endl;
    return 0;
}
