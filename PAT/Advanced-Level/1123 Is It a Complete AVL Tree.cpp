#include <iostream>
#include <queue>
#include <vector>

struct node
{
    int data = 0;
    node *left = NULL;
    node *right = NULL;
};

int depth(node *head);
void turn_left(node *&head);
void turn_right(node *&head);
int build_tree(node *&head, int data);
int max_tree_index(node *head, int index);
std::vector<int> level_travel(node *head);

int main()
{
    node *head = NULL;
    int N = 0, key = 0;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> key;
        build_tree(head, key);
    }
    std::vector<int> sequence = level_travel(head);
    for (auto iter = sequence.begin(); iter != sequence.end(); iter++)
        std::cout << *iter << (iter != sequence.end() - 1 ? " " : "\n");
    int max = max_tree_index(head, 1);
    std::cout << (max == N ? "YES" : "NO") << std::endl;
    return 0;
}

int depth(node *head)
{
    if (head == NULL)
        return 0;
    return std::max(depth(head->left), depth(head->right)) + 1;
}

void turn_left(node *&head)
{
    node *right = head->right;
    head->right = right->left;
    right->left = head;
    head = right;
}

void turn_right(node *&head)
{
    node *left = head->left;
    head->left = left->right;
    left->right = head;
    head = left;
}

int build_tree(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node();
        head->data = data;
        return 1;
    }
    int leftDepth = 0, rightDepth = 0;
    if (data < head->data)
    {
        leftDepth = build_tree(head->left, data);
        rightDepth = depth(head->right);
    }
    else
    {
        leftDepth = depth(head->left);
        rightDepth = build_tree(head->right, data);
    }
    if (leftDepth - rightDepth == 2)
    {
        if (data > head->left->data)
            turn_left(head->left);
        turn_right(head);
    }
    else if (leftDepth - rightDepth == -2)
    {
        if (data < head->right->data)
            turn_right(head->right);
        turn_left(head);
    }
    return depth(head);
}

int max_tree_index(node *head, int index)
{
    int leftIndex = index, rightIndex = index;
    if (head->right)
        rightIndex = max_tree_index(head->right, index * 2 + 1);
    if (head->left)
        leftIndex = max_tree_index(head->left, index << 1);
    return std::max(leftIndex, rightIndex);
}

std::vector<int> level_travel(node *head)
{
    std::vector<int> result;
    std::queue<node *> queue;
    queue.push(head);
    while (!queue.empty())
    {
        node *n = queue.front();
        queue.pop();
        result.push_back(n->data);
        if (n->left)
            queue.push(n->left);
        if (n->right)
            queue.push(n->right);
    }
    return result;
}
