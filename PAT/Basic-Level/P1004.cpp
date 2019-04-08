#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class student
{
  public:
    string name;
    string number;
    int score;
    int operator<(const student &a)
    {
        return this->score < a.score;
    }
};
int main()
{
    int count;
    cin >> count;
    student *data = new student[count];
    for (int i = 0; i < count; i++)
        cin >> data[i].name >> data[i].number >> data[i].score;
    sort(data, data + count);
    cout << data[count - 1].name << " " << data[count - 1].number << endl;
    cout << data[0].name << " " << data[0].number << endl;
    return 0;
}
