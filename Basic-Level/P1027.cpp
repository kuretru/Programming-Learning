#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int main()
{
    int count, n = 0, used = 0;
    string symbol;
    cin >> count >> symbol;
    for (int i = 1; used <= count; i += 2)
    {
        int increment = i == 1 ? i : i * 2;
        if (used + increment > count)
            break;
        used += increment;
        n++;
    }
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        for (int j = 1; j <= n - abs(n - i) - 1; j++)
            cout << " ";
        for (int j = 1; j <= 2 * (abs(n - i) + 1) - 1; j++)
            cout << symbol;
        cout << endl;
    }
    cout << count - used << endl;
    return 0;
}
