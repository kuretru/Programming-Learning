#include <iostream>
#include <string>
using namespace std;
int main()
{
    int N;
    string option;
    cin >> N;
    while (N--)
    {
        for (int i = 0; i < 4; i++)
        {
            cin >> option;
            if (option[2] == 'T')
                cout << (char)(option[0] - 16);
        }
    }
    cout << endl;
    return 0;
}
