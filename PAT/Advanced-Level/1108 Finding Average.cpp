#include <cstdio>
#include <iostream>
#include <string>

const double ERROR = 5000;

double legal(std::string number)
{
    // 负号和正数可以不用判断
    int dotCount = 0, negativeCount = 0, integerCount = 0, decimalCount = 0;
    for (int i = 0; i < number.length(); i++)
    {
        if (number[i] == '.')
            dotCount++;
        else if (number[i] == '-')
            negativeCount++;
        else if (number[i] < '0' || number[i] > '9')
            return ERROR;
        else if (dotCount == 0)
            integerCount++;
        else if (dotCount > 0)
            decimalCount++;
    }
    if (dotCount > 1 || integerCount > 4 || decimalCount > 2)
        return ERROR;
    if (negativeCount > 1 || (negativeCount == 1 && number[0] != '-'))
        return ERROR;
    double result = std::stod(number);
    if (result > 1000 || result < -1000)
        return ERROR;
    return result;
}

int main()
{
    int N, count = 0;
    double sum = 0;
    std::cin >> N;
    while (N--)
    {
        std::string number;
        std::cin >> number;
        double result = legal(number);
        if (ERROR == result)
        {
            std::cout << "ERROR: " << number << " is not a legal number" << std::endl;
            continue;
        }
        count++;
        sum += result;
    }
    if (count == 1)
        printf("The average of 1 number is %.2lf\n", sum);
    else if (count > 1)
        printf("The average of %d numbers is %.2lf\n", count, sum / count);
    else
        printf("The average of 0 numbers is Undefined\n");
    return 0;
}
