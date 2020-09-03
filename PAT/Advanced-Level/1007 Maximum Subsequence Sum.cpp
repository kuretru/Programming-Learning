#include <iostream>
#include <vector>

int main()
{
    int K = 0, tmp = 0, tmpLeft = 0;
    std::cin >> K;
    int result = 0, left = 0, right = K - 1;
    std::vector<int> data(K);
    for (int i = 0; i < K; i++)
        std::cin >> data[i];
    for (int i = 0; i < K; i++)
    {
        tmp += data[i];
        if (tmp < 0)
        {
            tmp = 0;
            tmpLeft = i + 1;
        }
        else if (tmp > result || result == 0)
        {
            result = tmp;
            left = tmpLeft;
            right = i;
        }
    }
    std::cout << result << " " << data[left] << " " << data[right] << std::endl;
    return 0;
}
