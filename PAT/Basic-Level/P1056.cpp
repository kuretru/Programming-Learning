#include <iostream>
using namespace std;
int main()
{
    int count, n, sum = 0;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> n;
        sum += n;
    }
    sum *= 11 * (count - 1);
    cout << sum << endl;
    return 0;
}
