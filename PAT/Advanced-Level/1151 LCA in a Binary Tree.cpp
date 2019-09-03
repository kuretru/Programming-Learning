#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using std::vector;

struct node
{
    int value = 0;
    node *left = NULL;
    node *right = NULL;
    node *parent = NULL;
    int depth = 0;
};

void buildTree(node *&head, vector<int> &in, vector<int> &pre, int inStart, int inEnd, int preStart)
{
    if (inStart > inEnd)
        return;
    head = new node();
    head->value = pre[preStart];
    int index = std::distance(in.begin(), std::find(in.begin(), in.end(), pre[preStart]));
    buildTree(head->left, in, pre, inStart, index - 1, preStart + 1);
    buildTree(head->right, in, pre, index + 1, inEnd, preStart + (index - inStart + 1));
}

void setParams(node *head, std::map<int, node *> &table, node *parent, int depth)
{
    if (!head)
        return;
    table[head->value] = head;
    head->parent = parent;
    head->depth = depth;
    setParams(head->left, table, head, depth + 1);
    setParams(head->right, table, head, depth + 1);
}

int main()
{
    int M = 0, N = 0;
    std::cin >> M >> N;
    vector<int> inorder(N), preorder(N);
    for (int i = 0; i < N; i++)
        std::cin >> inorder[i];
    for (int i = 0; i < N; i++)
        std::cin >> preorder[i];
    std::map<int, node *> table;
    node *head = NULL;
    buildTree(head, inorder, preorder, 0, N - 1, 0);
    setParams(head, table, NULL, 1);
    while (M--)
    {
        int U = 0, V = 0;
        std::cin >> U >> V;
        int foundU = table.count(U), foundV = table.count(V);
        if (!foundU && !foundV)
            printf("ERROR: %d and %d are not found.\n", U, V);
        else if (!foundU || !foundV)
            printf("ERROR: %d is not found.\n", foundU ? V : U);
        if (!foundU || !foundV)
            continue;
        node *LCA = NULL, *nodeU = table[U], *nodeV = table[V];
        while (nodeU != nodeV)
        {
            if (nodeU->depth >= nodeV->depth)
                nodeU = nodeU->parent;
            else
                nodeV = nodeV->parent;
        }
        LCA = nodeU, nodeU = table[U], nodeV = table[V];
        if (LCA == nodeU || LCA == nodeV)
            printf("%d is an ancestor of %d.\n", LCA == nodeU ? U : V, LCA == nodeU ? V : U);
        else
            printf("LCA of %d and %d is %d.\n", U, V, LCA->value);
    }
    return 0;
}
