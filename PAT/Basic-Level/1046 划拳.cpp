#include <iostream>

int main()
{
    int a = 0, b = 0, count = 0;
    std::cin >> count;
    while (count--)
    {
        int x1, x2, y1, y2;
        std::cin >> x1 >> x2 >> y1 >> y2;
        if (x1 + y1 == x2 && x1 + y1 != y2)
            b++;
        if (x1 + y1 != x2 && x1 + y1 == y2)
            a++;
    }
    printf("%d %d\n", a, b);
    return 0;
}
