// 1.根据先序序列和后序序列随不能确定左右子树，但可以确定哪些是该节点的子孙(从先序的头开始查找)
// 2.依次从父节点删除非直系子孙
// 3.若该节点剩余的子孙个数为1，则无法唯一确定一棵树(可以是左孩子，亦可以是右孩子)

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using std::vector;

int indexOfPost(vector<int> &post, int value)
{
    return std::distance(post.begin(), std::find(post.begin(), post.end(), value));
}

void inorderTravel(vector<std::unordered_set<int>> &children, int index, vector<int> pre, vector<int> &result)
{
    if (!children[index].empty())
    {
        inorderTravel(children, *children[index].begin(), pre, result);
        children[index].erase(children[index].begin());
    }
    result.push_back(pre[index]);
    if (!children[index].empty())
        inorderTravel(children, *children[index].begin(), pre, result);
}

int main()
{
    int N = 0;
    std::cin >> N;
    vector<int> pre(N), post(N), postIndex(N);
    vector<std::unordered_set<int>> children(N);
    for (int i = 0; i < N; i++)
        std::cin >> pre[i];
    for (int i = 0; i < N; i++)
        std::cin >> post[i];
    for (int i = 0; i < N; i++)
        postIndex[i] = indexOfPost(post, pre[i]);
    for (int i = 0; i < N; i++)
        for (int j = N - 1; j > i; j--) // unordered_set 是逆序的，所以倒着插入
            if (postIndex[j] < postIndex[i])
                children[i].insert(j);
    for (int i = 0; i < N; i++)
    {
        if (children[i].size() < 2)
            continue;
        for (auto j = children[i].begin(); j != children[i].end(); j++)
            for (auto k = children[*j].begin(); k != children[*j].end(); k++)
                if (children[i].count(*k))
                    children[i].erase(*k);
    }
    bool unique = true;
    for (int i = 0; i < N; i++)
        if (children[i].size() == 1)
            unique = false;
    std::cout << (unique ? "Yes" : "No") << std::endl;
    vector<int> result;
    inorderTravel(children, 0, pre, result);
    for (auto iter = result.begin(); iter != result.end(); iter++)
        std::cout << *iter << (iter != result.end() - 1 ? " " : "\n");
    return 0;
}
