#include <iostream>
#include <vector>
std::vector<int> in, post;
std::vector<std::vector<int>> tree(30);
bool desc = true;
void toLevel(int inLeft, int inRight, int postIndex, int level)
{
    if (inLeft > inRight)
        return;
    int inIndex = inRight;
    while (in[inIndex] != post[postIndex] && inIndex >= inLeft)
        inIndex--;
    tree[level].push_back(post[postIndex]);
    toLevel(inLeft, inIndex - 1, postIndex - (inRight - inIndex) - 1, level + 1);
    toLevel(inIndex + 1, inRight, postIndex - 1, level + 1);
}
int main()
{
    int N;
    std::cin >> N;
    in.resize(N);
    post.resize(N);
    for (int i = 0; i < N; i++)
        std::cin >> in[i];
    for (int i = 0; i < N; i++)
        std::cin >> post[i];
    toLevel(0, N - 1, N - 1, 0);
    std::vector<int> result;
    for (int i = 0; i < 30; i++)
    {
        if (i % 2 == 1)
            for (auto iter = tree[i].begin(); iter != tree[i].end(); iter++)
                result.push_back(*iter);
        else
            for (auto iter = tree[i].rbegin(); iter != tree[i].rend(); iter++)
                result.push_back(*iter);
    }
    for (int i = 0; i < N; i++)
        std::cout << result[i] << (i < (N - 1) ? " " : "\n");
    return 0;
}
