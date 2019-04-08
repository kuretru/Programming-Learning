#include <stdio.h>
int main()
{
    int kwh;
    double price;
    scanf("%d", &kwh);
    if (kwh <= 150)
        price = kwh * 0.4463;
    else if (kwh <= 400)
        price = 66.945 + (kwh - 150) * 0.4663;
    else
        price = 183.52 + (kwh - 400) * 0.5663;
    printf("%.1lf", price);
    return 0;
}
