#include <algorithm>
#include <iostream>

void solve(int &x, int &y)
{
    int data[4] = {0};
    for (int i = 0; x > 0; i++, x /= 10)
        data[i] = x % 10;
    std::sort(data, data + 4);
    y = 0;
    for (int i = 0; i < 4; i++)
        y = y * 10 + data[i];
    std::reverse(data, data + 4);
    for (int i = 0; i < 4; i++)
        x = x * 10 + data[i];
}

int main()
{
    int x = 0, y = 0;
    std::cin >> x;
    do
    {
        solve(x, y);
        printf("%04d - %04d = %04d\n", x, y, x - y);
        x = x - y;
    } while (x != 6174 && x != 0);
    return 0;
}
