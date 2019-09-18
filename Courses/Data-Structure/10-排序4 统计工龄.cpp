#include <iostream>
#include <vector>
int main()
{
    int N, key;
    std::cin >> N;
    std::vector<int> data(51);
    while (N--)
    {
        std::cin >> key;
        data[key]++;
    }
    for (int i = 0; i <= 50; i++)
    {
        if (data[i] != 0)
            std::cout << i << ":" << data[i] << std::endl;
    }
    return 0;
}
