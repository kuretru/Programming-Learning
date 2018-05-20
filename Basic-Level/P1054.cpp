#include <cstring>
#include <iostream>
int main()
{
    int count, result = 0;
    char m[50], n[50];
    double sum = 0;
    std::cin >> count;
    while (count--)
    {
        double tmp;
        scanf("%s", m);
        sscanf(m, "%lf", &tmp);
        sprintf(n, "%.2lf", tmp);
        bool legal = true;
        for (int i = 0; i < strlen(m); i++)
            if (m[i] != n[i])
                legal = false;
        if (tmp < -1000 || tmp > 1000 || !legal)
        {
            printf("ERROR: %s is not a legal number\n", m);
        }
        else
        {
            sum += tmp;
            result++;
        }
    }
    if (result == 0)
        printf("The average of 0 numbers is Undefined");
    else if (result == 1)
        printf("The average of 1 number is %.2lf", sum);
    else
        printf("The average of %d numbers is %.2lf", result, sum / result);
    return 0;
}
