#include <iostream>

int main()
{
    int T = 0;
    std::cin >> T;
    for (int i = 1; i <= T; i++)
    {
        long long A = 0, B = 0, C = 0;
        std::cin >> A >> B >> C;
        long long sum = A + B;
        bool result = sum > C;
        if (A > 0 && B > 0 && sum < 0)
            result = !result;
        else if (A < 0 && B < 0 && sum >= 0)
            result = !result;
        std::cout << "Case #" << i << ": " << (result ? "true" : "false") << std::endl;
    }
    return 0;
}
