#include <iostream>
#include <vector>
int main()
{
    int K;
    std::cin >> K;
    std::vector<int> data(K, 0);
    for (int i = 0; i < K; i++)
        std::cin >> data[i];
    int sum = -1, first = data[0], last = data[K - 1], thisSum = 0, thisFirst = data[0];
    for (int i = 0; i < K; i++)
    {
        thisSum += data[i];
        if (thisSum > sum)
        {
            sum = thisSum;
            first = thisFirst;
            last = data[i];
        }
        else if (thisSum < 0)
        {
            thisSum = 0;
            thisFirst = data[i + 1];
        }
    }
    std::cout << (sum < 0 ? 0 : sum) << " " << first << " " << last << std::endl;
    return 0;
}
