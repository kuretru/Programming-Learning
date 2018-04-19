#include <iostream>
#include <map>
#include <string>
using namespace std;
struct examinee
{
    string id;
    int sj;
    int ks;
};
int main()
{
    map<int, examinee> data;
    int count, key;
    cin >> count;
    while (count--)
    {
        examinee e;
        cin >> e.id >> e.sj >> e.ks;
        data[e.sj] = e;
    }
    cin >> count;
    while (count--)
    {
        cin >> key;
        cout << data[key].id << " " << data[key].ks << endl;
    }
    return 0;
}
