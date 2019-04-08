#include <cmath>
#include <iostream>
#include <map>
#include <string>
using namespace std;
struct player
{
    string name;
    int rank;
    string award;
};
int isPrime(int n)
{
    int length = sqrt(n);
    for (int i = 2; i <= length; i++)
        if (n % i == 0)
            return false;
    return n > 1;
}
int main()
{
    map<string, player> data;
    int count, rank = 1;
    cin >> count;
    while (count--)
    {
        player p;
        cin >> p.name;
        p.rank = rank++;
        if (p.rank == 1)
            p.award = "Mystery Award";
        else if (isPrime(p.rank))
            p.award = "Minion";
        else
            p.award = "Chocolate";
        data[p.name] = p;
    }
    cin >> count;
    while (count--)
    {
        string name;
        cin >> name;
        cout << name << ": ";
        if (data[name].rank > 0)
        {
            cout << data[name].award << endl;
            data[name].award = "Checked";
        }
        else
            cout << "Are you kidding?" << endl;
    }
    return 0;
}
