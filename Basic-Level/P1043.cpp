#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    static char keys[] = {'P', 'A', 'T', 'e', 's', 't'};
    map<char, int> data;
    string text;
    cin >> text;
    for (int i = 0; i < text.length(); i++)
        data[text[i]]++;
    while (true)
    {
        bool finished = true;
        for (int i = 0; i < 6; i++)
        {
            if (data[keys[i]]-- > 0)
            {
                cout << keys[i];
                if (finished)
                    finished = false;
            }
        }
        if (finished)
            break;
    }
    return 0;
}
