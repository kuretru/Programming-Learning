#include <iostream>
#include <string>
using namespace std;
int main()
{
    int count;
    string symbol;
    cin >> count >> symbol;
    int end = count * 0.5 + 0.5;
    for (int i = 0; i < end; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (i == 0 || i == end - 1 || j == 0 || j == count - 1)
                cout << symbol;
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
