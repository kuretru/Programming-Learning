#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<string> list;
    vector<string>::reverse_iterator iter;
    string text;
    while (cin >> text)
        list.push_back(text);
    for (iter = list.rbegin(); iter != list.rend(); iter++)
        cout << *iter << (*iter != list.front() ? " " : "\n");
    return 0;
}
