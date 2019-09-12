#include <iostream>
#include <set>

int main()
{
    std::ios::sync_with_stdio(false);
    int N = 0, M = 0;
    std::cin >> N >> M;
    std::multiset<int> data;
    for (int i = 0, key = 0; i < N; i++)
    {
        std::cin >> key;
        data.insert(key);
    }
    for (int x : data)
    {
        if ((x < M - x && data.count(M - x)) || (x == M - x && data.count(x) > 1))
        {
            std::cout << x << " " << M - x << std::endl;
            return 0;
        }
    }
    std::cout << "No Solution" << std::endl;
    return 0;
}
