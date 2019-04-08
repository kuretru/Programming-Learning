#include <algorithm>
#include <iostream>
using namespace std;
void adjust(int n[])
{
    int data[4] = {0};
    for (int i = 0; n[0] > 0; i++, n[0] /= 10)
        data[i] = n[0] % 10;
    sort(data, data + 4);
    n[1] = 0;
    for (int i = 0; i < 4; i++)
        n[1] = n[1] * 10 + data[i];
    reverse(data, data + 4);
    for (int i = 0; i < 4; i++)
        n[0] = n[0] * 10 + data[i];
}
int main()
{
    int n[2];
    cin >> n[0];
    do
    {
        adjust(n);
        printf("%04d - %04d = %04d\n", n[0], n[1], n[0] - n[1]);
        n[0] = n[0] - n[1];
    } while (n[0] != 6174 && n[0] != 0);
    return 0;
}
