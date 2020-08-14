#include <iostream>
#include <set>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    int N = 0;
    std::cin >> N;
    std::vector<int> data(N);
    std::set<int> set, result;
    for (int i = 0; i < N; i++)
    {
        std::cin >> data[i];
        set.insert(data[i]);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int sum = data[i] + data[j];
            if (set.count(sum) == 1)
            {
                result.insert(sum);
            }
        }
    }
    std::cout << result.size() << std::endl;
    return 0;
}
