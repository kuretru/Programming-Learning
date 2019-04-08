#include <algorithm>
#include <iostream>
bool flag[4700];
int main()
{
    int count;
    std::cin >> count;
    int *data = new int[count];
    for (int i = 0; i < count; i++)
        std::cin >> data[i];
    std::sort(data, data + count);
    for (int i = 0; i < count; i++)
    {
        int tmp = data[i];
        while (tmp != 1)
        {
            if (tmp % 2 == 0)
                tmp /= 2;
            else
                tmp = (3 * tmp + 1) / 2;
            if (flag[tmp])
                break;
            else
                flag[tmp] = true;
        }
    }
    bool start = true;
    for (int i = count - 1; i >= 0; i--)
    {
        if (!flag[data[i]])
        {
            if (start)
                start = false;
            else
                std::cout << " ";
            std::cout << data[i];
        }
    }
    std::cout << std::endl;
    return 0;
}
