#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> data;
    int count;
    cin >> count;
    while (count--)
    {
        int n, sum = 0;
        cin >> n;
        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
        data.insert(sum);
    }
    cout << data.size() << endl;
    for (auto iter = data.begin(); iter != data.end(); iter++)
    {
        if (iter != data.begin())
            cout << " ";
        cout << *iter;
    }
    cout << endl;
    return 0;
}
