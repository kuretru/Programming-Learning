#include <iostream>
#include <set>

int main()
{
    int N = 0;
    std::cin >> N;
    std::set<int> result;
    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        sum += (int)(i / 2);
        sum += (int)(i / 3);
        sum += (int)(i / 5);
        result.insert(sum);
    }
    std::cout << result.size() << std::endl;
    return 0;
}
