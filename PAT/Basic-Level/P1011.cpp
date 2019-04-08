#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long a, b, c;
        cin >> a >> b >> c;
        if (a + b > c)
            cout << "Case #" << i << ": true" << endl;
        else
            cout << "Case #" << i << ": false" << endl;
    }
    return 0;
}
