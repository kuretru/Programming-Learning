#include <iostream>
using namespace std;
int main()
{
    int a, b;
    bool zero = true;
    while (cin >> a >> b)
    {
        if (b < 1)
        {
            if (zero)
                cout << "0 0";
            break;
        }
        if (zero)
            zero = false;
        else
            cout << " ";
        cout << a * b << " " << b - 1;
    }
    cout << endl;
    return 0;
}
