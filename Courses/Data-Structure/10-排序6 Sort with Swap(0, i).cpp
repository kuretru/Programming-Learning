#include <iostream>
#include <vector>

int main()
{
    int count, result = 0;
    std::cin >> count;
    std::vector<int> data(count);
    std::vector<bool> found(count, false);
    for (int i = 0; i < count; i++)
        std::cin >> data[i];
    for (int i = 0; i < count; i++)
    {
        if (found[i])
            continue;
        if (data[i] == i)
            continue;
        found[i] = true;
        int ring = 1;
        for (int j = data[i]; !found[j]; ring++)
        {
            found[j] = true;
            j = data[j];
        }
        result += ring + (i != 0 ? 1 : -1);
    }
    std::cout << result << std::endl;
    return 0;
}
