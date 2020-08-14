#include <iostream>
#include <string>

int main()
{
    std::string isbn = "";
    std::cin >> isbn;
    int sum = 0;
    for (int i = 0, j = 1; i < 11; i++)
    {
        if (i == 1 || i == 5)
            continue;
        sum += j++ * (isbn[i] - '0');
    }
    sum %= 11;
    if (sum == 10)
    {
        if (isbn[12] == 'X')
            isbn = "";
        else
            isbn[12] = 'X';
    }
    else
    {
        if (isbn[12] - '0' == sum)
            isbn = "";
        else
            isbn[12] = sum + '0';
    }
    if (isbn == "")
        std::cout << "Right" << std::endl;
    else
        std::cout << isbn << std::endl;
    return 0;
}
