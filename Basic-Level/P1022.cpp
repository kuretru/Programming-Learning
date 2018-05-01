#include <iostream>
#include <string>
using namespace std;
int main()
{
    string result = "";
    int A, B, D;
    cin >> A >> B >> D;
    A += B;
    if (A == 0)
        cout << 0;
    while (A > 0)
    {
        result = (char)(A % D + '0') + result;
        A /= D;
    }
    cout << result << endl;
    return 0;
}
