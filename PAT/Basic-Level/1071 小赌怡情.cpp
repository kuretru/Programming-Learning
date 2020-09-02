#include <iostream>

int main()
{
    int T = 0, K = 0;
    std::cin >> T >> K;
    while (K--)
    {
        int n1, b, t, n2;
        std::cin >> n1 >> b >> t >> n2;
        if (t > T)
        {
            printf("Not enough tokens.  Total = %d.\n", T);
            continue;
        }
        if ((b == 0 && n1 > n2) || (b == 1 && n1 < n2))
            printf("Win %d!  Total = %d.\n", t, T += t);
        else
            printf("Lose %d.  Total = %d.\n", t, (T -= t) < 0 ? 0 : T);
        if (T <= 0)
        {
            std::cout << "Game Over." << std::endl;
            break;
        }
    }
    return 0;
}
