#include <iostream>

int main()
{
    int N = 0, result = 0;
    std::cin >> N;
    int left = N, right = 0;
    for (int pow = 1; left > 0; pow *= 10)
    {
        // 左边部分为当前位带来的1
        result += left / 10 * pow;
        // 右边部分为当前位带来的1
        if (left % 10 == 1)
            result += right + 1;
        else if (left % 10 > 1)
            result += pow;
        // 下一轮
        right += left % 10 * pow;
        left /= 10;
    }
    std::cout << result << std::endl;
    return 0;
}
