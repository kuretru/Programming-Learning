#include <cmath>
#include <iostream>
#include <vector>

bool isPrime(int number)
{
    int length = sqrt(number);
    for (int i = 2; i <= length; i++)
        if (number % i == 0)
            return false;
    return number > 1;
}

int main()
{
    int M, N, key, index = -1;
    std::cin >> M >> N;
    while (!isPrime(M))
        M++;
    std::vector<int> data(M, -1);
    for (int i = 0; i < N; i++)
    {
        std::cin >> key;
        for (int j = 0; j < M; j++)
        {
            index = (key + j * j) % M;
            if (data[index] == -1)
            {
                data[index] = key;
                break;
            }
            if (j == M - 1)
                index = -1;
        }
        if (index != -1)
            std::cout << index;
        else
            std::cout << "-";
        std::cout << (i < N - 1 ? " " : "\n");
    }
    return 0;
}
