#include <iostream>
#include <string>
using namespace std;
int main()
{
    string d;
    int N, count;
    cin >> d >> N;
    while (--N)
    {
        string s = "";
        for (int i = 0; i < d.length(); i += count)
        {
            char c = d[i];
            count = 1;
            for (int j = i + 1; j < d.length(); j++)
            {
                if (d[j] == d[j - 1])
                    count++;
                else
                    break;
            }
            s += c;
            s += count + '0';
        }
        d = s;
    }
    cout << d << endl;
    return 0;
}
