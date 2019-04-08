#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, int> list;
    map<int, int>::iterator iter;
    int count, group, player, score;
    cin >> count;
    while (count--)
    {
        scanf("%d-%d %d", &group, &player, &score);
        list[group] += score;
    }
    int max = list.begin()->first;
    for (iter = list.begin(); iter != list.end(); iter++)
        if (iter->second > list[max])
            max = iter->first;
    cout << max << " " << list[max] << endl;
    return 0;
}
