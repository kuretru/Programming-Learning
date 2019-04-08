#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, int> data;
    map<int, int>::reverse_iterator riter;
    int count, n;
    cin >> count;
    for (int i = 1; i <= count; i++)
    {
        cin >> n;
        n -= i;
        n = n > 0 ? n : -n;
        data[n]++;
    }
    for (riter = data.rbegin(); riter != data.rend(); riter++)
        if (riter->second > 1)
            cout << riter->first << " " << riter->second << endl;
    return 0;
}
