#include <iostream>
#include <vector>
int main()
{
    int M, N, U, V;
    std::cin >> M >> N;
    std::vector<int> inorder(N), preorder(N);
    for (int i = 0; i < N; i++)
        std::cin >> inorder[i];
    for (int i = 0; i < N; i++)
        std::cin >> preorder[i];
    while (M--)
    {
        std::cin >> U >> V;
        }
    return 0;
}
