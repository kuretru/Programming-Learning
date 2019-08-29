#include <iostream>
#include <vector>

using std::vector;

int toPost(vector<int> &pre, vector<int> &in, int preIndex, int inLeft, int inRight)
{
    if (inLeft > inRight)
        return -1;
    int inIndex;
    for (inIndex = inLeft; inIndex <= inRight; inIndex++)
        if (in[inIndex] == pre[preIndex])
            break;
    int left = toPost(pre, in, preIndex + 1, inLeft, inIndex - 1);
    if (left != -1)
        return left;
    int right = toPost(pre, in, preIndex + 1 + inIndex - inLeft, inIndex + 1, inRight);
    if (right != -1)
        return right;
    return in[inIndex];
}

int main()
{
    int N = 0;
    std::cin >> N;
    vector<int> pre(N), in(N);
    for (int i = 0; i < N; i++)
        std::cin >> pre[i];
    for (int i = 0; i < N; i++)
        std::cin >> in[i];
    int result = toPost(pre, in, 0, 0, N - 1);
    std::cout << result << std::endl;
    return 0;
}
