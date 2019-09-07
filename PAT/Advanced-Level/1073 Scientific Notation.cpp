#include <iostream>
#include <string>

int main()
{
    std::string A = "";
    std::cin >> A;
    std::cout << (A[0] == '-' ? "-" : "");
    int index = A.find("E");
    int decimal = index - 3;
    int exp = std::stoi(A.substr(index + 2));
    if (A[index + 1] == '+')
    {
        std::cout << A[1];
        if (exp >= decimal)
        {
            std::cout << A.substr(3, decimal);
            for (int i = decimal; i < exp; i++)
                std::cout << "0";
        }
        else
        {
            std::cout << A.substr(3, exp) << ".";
            std::cout << A.substr(3 + exp, decimal - exp);
        }
    }
    else
    {
        std::cout << "0.";
        for (int i = 1; i < exp; i++)
            std::cout << "0";
        std::cout << A[1] << A.substr(3, decimal);
    }
    std::cout << std::endl;
    return 0;
}
