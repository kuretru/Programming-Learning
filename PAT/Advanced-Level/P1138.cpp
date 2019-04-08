#include <iostream>
#include <vector>
std::vector<int> pre, in;
int toPost(int preIndex, int inLeft, int inRight)
{
    if (inLeft > inRight)
        return -1;
    int inIndex;
    for (inIndex = inLeft; inIndex <= inRight; inIndex++)
        if (in[inIndex] == pre[preIndex])
            break;
    int left = toPost(preIndex + 1, inLeft, inIndex - 1);
    if (left != -1)
        return left;
    int right = toPost(preIndex + 1 + inIndex - inLeft, inIndex + 1, inRight);
    if (right != -1)
        return right;
    return in[inIndex];
}
int main()
{
    int N, result;
    std::cin >> N;
    pre.resize(N);
    in.resize(N);
    for (int i = 0; i < N; i++)
        std::cin >> pre[i];
    for (int i = 0; i < N; i++)
        std::cin >> in[i];
    result = toPost(0, 0, N - 1);
    std::cout << result << std::endl;
    return 0;
}
