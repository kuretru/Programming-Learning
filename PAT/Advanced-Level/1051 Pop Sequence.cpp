#include <iostream>
#include <stack>
#include <vector>

bool solve(std::vector<int> &data, int M, int N)
{
    int start = 1;
    std::stack<int> stack;
    for (int i = 1; i <= N; i++)
    {
        if (data[i] > start)
        {
            while (data[i] != start)
                stack.push(start++);
            if (stack.size() + 1 > M)
                return false;
            start++;
        }
        else if (data[i] < start)
        {
            if (stack.top() != data[i])
                return false;
            stack.pop();
        }
        else
            start++;
    }
    return true;
}

int main()
{
    int M = 0, N = 0, K = 0;
    std::cin >> M >> N >> K;
    while (K--)
    {
        std::vector<int> data(N + 1);
        for (int i = 1; i <= N; i++)
            std::cin >> data[i];
        bool result = solve(data, M, N);
        std::cout << (result ? "YES" : "NO") << std::endl;
    }
    return 0;
}
