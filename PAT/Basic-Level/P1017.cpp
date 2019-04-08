#include <iostream>
using namespace std;
int main()
{
    string A;
    int B, R = 0;
    bool first = true;
    cin >> A >> B;
    for (int i = 0; i < A.length(); i++)
    {
        R = R * 10 + A[i] - '0';
        if (R / B != 0 || (R / B == 0 && (!first || A.length() == 1)))
            cout << R / B;
        R %= B;
        first = false;
    }
    cout << " " << R << endl;
    return 0;
}
