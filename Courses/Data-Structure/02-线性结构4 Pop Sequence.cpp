#include <iostream>
#include <stack>
int main()
{
    int M, N, K;
    std::cin >> M >> N >> K;
    while (K--)
    {
        bool possible = true;
        std::stack<int> stack;
        int key, number = 1;
        for (int i = 0; i < N; i++)
        {
            std::cin >> key;
            while ((stack.empty() || (!stack.empty() && stack.top() != key)) && number <= N)
                stack.push(number++);
            if (stack.size() > M)
                possible = false;
            if (stack.top() == key)
                stack.pop();
        }
        if (!stack.empty())
            possible = false;
        std::cout << (possible ? "YES" : "NO") << std::endl;
    }
    return 0;
}
