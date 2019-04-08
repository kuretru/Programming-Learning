#include <algorithm>
#include <iostream>
int main()
{
    float sum = 1, data[3];
    char table[3] = {'W', 'T', 'L'};
    for (int i = 0; i < 3; i++)
    {
        std::cin >> data[0] >> data[1] >> data[2];
        int max = std::distance(data, std::max_element(data, data + 3));
        sum *= data[max];
        std::cout << table[max] << " ";
    }
    printf("%.2f\n", (sum * 0.65 - 1) * 2);
    return 0;
}
