#include <iostream>
#include <vector>

int main()
{
    std::vector<bool> flags(5, false);
    int A[5] = {0}, N = 0, number = 0, symbol = 1, A4 = 0;
    std::cin >> N;
    while (N--)
    {
        std::cin >> number;
        int type = number % 5;
        if (type != 0 && type != 4)
            flags[type] = true;
        switch (type)
        {
        case 0:
            if (number % 2 == 0)
            {
                A[0] += number;
                flags[0] = true;
            }
            break;
        case 1:
            A[1] += number * symbol;
            symbol *= -1;
            break;
        case 2:
            A[2]++;
            break;
        case 3:
            A[3] += number;
            A4++;
            break;
        case 4:
            if (number > A[4])
            {
                A[4] = number;
                flags[4] = true;
            }
            break;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (!flags[i])
            std::cout << "N";
        else
        {
            if (i != 3)
                std::cout << A[i];
            else
                printf("%.1f", A[3] * 1.0 / A4);
        }
        std::cout << (i != 4 ? " " : "\n");
    }
    return 0;
}
