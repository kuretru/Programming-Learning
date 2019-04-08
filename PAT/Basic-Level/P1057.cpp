#include <iostream>
using namespace std;
int main()
{
    int sum = 0, count[2] = {0};
    char c;
    while ((c = getchar()) != '\n')
    {
        if (c >= 'a' && c <= 'z')
            sum += c - 'a' + 1;
        else if (c >= 'A' && c <= 'Z')
            sum += c - 'A' + 1;
    }
    while (sum > 0)
    {
        count[sum % 2]++;
        sum /= 2;
    }
    printf("%d %d\n", count[0], count[1]);
    return 0;
}
