#include <iostream>
#include <map>
const int empty = 19960203;
std::map<int, int> result;
struct node
{
    node *left = NULL, *right = NULL;
    int data = empty;
};
void insert(node *head, int key, int level)
{
    if (head->data == empty)
    {
        head->data = key;
        result[level]++;
    }
    else if (key <= head->data)
    {
        if (head->left == NULL)
            head->left = new node();
        insert(head->left, key, level + 1);
    }
    else if (key > head->data)
    {
        if (head->right == NULL)
            head->right = new node();
        insert(head->right, key, level + 1);
    }
}
int main()
{
    int N, key;
    std::cin >> N;
    node *head = new node();
    while (N--)
    {
        std::cin >> key;
        insert(head, key, 0);
    }
    int x = result.rbegin()->second;
    int y = result.size() == 1 ? 0 : (++result.rbegin())->second;
    printf("%d + %d = %d\n", x, y, x + y);
    return 0;
}
