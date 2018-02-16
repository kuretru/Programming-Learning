#include <stdio.h>
int main()
{
    double s, x, location = 0, speed = 7;
    scanf("%lf %lf", &s, &x);
    while (location < s - x)
    {
        location += speed;
        speed *= 0.98;
    }
    if (location + speed > s + x)
        printf("n");
    else
        printf("y");
    return 0;
}
