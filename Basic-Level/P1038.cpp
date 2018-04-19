#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, int> data;
    int count, n;
    cin >> count;
    while (count--)
    {
        cin >> n;
        data[n]++;
    }
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> n;
        cout << data[n] << (i != count - 1 ? " " : "\n");
    }
    return 0;
}
