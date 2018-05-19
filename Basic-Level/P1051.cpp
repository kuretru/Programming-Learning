#include <cmath>
#include <iostream>
int main()
{
    double R1, P1, R2, P2;
    std::cin >> R1 >> P1 >> R2 >> P2;
    double a = R1 * cos(P1), b = R1 * sin(P1);
    double c = R2 * cos(P2), d = R2 * sin(P2);
    double R = a * c - b * d;
    double P = b * c + a * d;
    if (fabs(R) < 0.005)
        std::cout << "0.00";
    else
        printf("%.2lf", R);
    if (fabs(P) < 0.005)
        std::cout << "+0.00i";
    else if (P < 0)
        printf("%.2lfi\n", P);
    else
        printf("+%.2lfi\n", P);
    return 0;
}
