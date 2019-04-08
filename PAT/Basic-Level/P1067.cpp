#include <iostream>
#include <string>
using namespace std;
int main()
{
    string password;
    int maxTimes;
    cin >> password >> maxTimes;
    getchar();
    while (maxTimes--)
    {
        string text;
        getline(cin, text);
        if (text == "#")
            return 0;
        if (text == password)
        {
            cout << "Welcome in" << endl;
            return 0;
        }
        else
            cout << "Wrong password: " << text << endl;
    }
    cout << "Account locked" << endl;
    return 0;
}
