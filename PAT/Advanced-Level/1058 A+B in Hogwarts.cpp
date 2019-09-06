#include <iostream>

long long input()
{
    long long galleon = 0, sickle = 0, knut = 0;
    scanf("%lld.%lld.%lld", &galleon, &sickle, &knut);
    sickle += galleon * 17;
    knut += sickle * 29;
    return knut;
}

int main()
{
    long long A = input(), B = input();
    long long sum = A + B;
    printf("%lld.%lld.%lld", sum / 29 / 17, sum / 29 % 17, sum % 29);
    return 0;
}
