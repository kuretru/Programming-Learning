#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct student
{
    int number;
    int moral;
    int talent;
    int type;
};
int cmp(student x, student y)
{
    if (x.type == y.type)
    {
        int totalX = x.moral + x.talent;
        int totalY = y.moral + y.talent;
        if (totalX == totalY)
        {
            if (x.moral == y.moral)
            {
                return x.number < y.number;
            }
            return x.moral > y.moral;
        }
        return totalX > totalY;
    }
    return x.type < y.type;
}
int main()
{
    int N, L, H;
    cin >> N >> L >> H;
    vector<student> list;
    for (int i = 0; i < N; i++)
    {
        student data;
        cin >> data.number >> data.moral >> data.talent;
        if (data.moral < L || data.talent < L)
            continue;
        if (data.moral >= H && data.talent >= H)
            data.type = 1;
        else if (data.moral >= H)
            data.type = 2;
        else if (data.talent < H && data.moral >= data.talent)
            data.type = 3;
        else
            data.type = 4;
        list.push_back(data);
    }
    sort(list.begin(), list.end(), cmp);
    cout << list.size() << endl;
    for (int i = 0; i < (int)list.size(); i++)
        printf("%d %d %d\n", list[i].number, list[i].moral, list[i].talent);
    return 0;
}
