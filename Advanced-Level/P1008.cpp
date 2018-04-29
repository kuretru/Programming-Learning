#include <iostream>
using namespace std;
int main()
{
    int count, cur = 0, n;
    cin >> count;
    int result = count * 5;
    while (count--)
    {
        cin >> n;
        if (n > cur)
            result += (n - cur) * 6;
        else
            result += (cur - n) * 4;
        cur = n;
    }
    cout << result << endl;
    return 0;
}
