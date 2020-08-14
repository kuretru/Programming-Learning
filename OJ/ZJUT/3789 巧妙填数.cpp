#include <iostream>
#include <set>

bool judge(int x, int y, int z)
{
    std::set<int> data;
    data.insert(0);
    for (; x > 0; x /= 10)
        data.insert(x % 10);
    for (; y > 0; y /= 10)
        data.insert(y % 10);
    for (; z > 0; z /= 10)
        data.insert(z % 10);
    return data.size() == 10;
}

int main()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            for (int k = 1; k <= 9; k++)
            {
                if (i == j || j == k || i == k)
                    continue;
                int x = i * 100 + j * 10 + k;
                int y = x * 2, z = x * 3;
                if (z < 1000 && judge(x, y, z))
                    printf("%d %d %d\n", x, y, z);
            }
        }
    }
    return 0;
}
