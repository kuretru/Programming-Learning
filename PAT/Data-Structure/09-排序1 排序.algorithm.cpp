#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
    std::ios::sync_with_stdio(false);
    int count;
    std::cin >> count;
    std::vector<int> data(count);
    for (int i = 0; i < count; i++)
        std::cin >> data[i];
    std::sort(data.begin(), data.end());
    for (int i = 0; i < count; i++)
        std::cout << data[i] << (i < count - 1 ? " " : "\n");
    return 0;
}
