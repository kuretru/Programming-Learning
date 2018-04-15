#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, int> list;
    map<int, int>::iterator iter;
    int count;
    cin >> count;
    while (count--)
    {
        int number, score;
        cin >> number >> score;
        list[number] += score;
    }
    int max = 1;
    for (int i = 2; i <= (int)list.size(); i++)
        if (list[i] > list[max])
            max = i;
    cout << max << " " << list[max] << endl;
    return 0;
}
