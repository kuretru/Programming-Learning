#include <iostream>
#include <string>
using namespace std;
static int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
static char digit[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
bool check(string id)
{
    int check = 0;
    for (int i = 0; i < 17; i++)
        check += (id[i] - '0') * weight[i];
    check %= 11;
    if (digit[check] == id[17])
        return true;
    id[17] = digit[check];
    return false;
}
int main()
{
    int count;
    bool allPassed = true;
    cin >> count;
    while (count--)
    {
        string id;
        cin >> id;
        if (check(id))
            continue;
        else if (allPassed)
            allPassed = false;
        cout << id << endl;
    }
    if (allPassed)
        cout << "All passed" << endl;
    return 0;
}
