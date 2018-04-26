#include <iostream>
#include <string>
using namespace std;
struct player
{
    string name;
    int score;
};
int main()
{
    int count;
    player max, min;
    max.score = INT32_MAX;
    min.score = 0;
    cin >> count;
    while (count--)
    {
        player p;
        int a, b;
        cin >> p.name >> a >> b;
        p.score = a * a + b * b;
        if (p.score < max.score)
            max = p;
        if (p.score > min.score)
            min = p;
    }
    cout << max.name << " " << min.name << endl;
    return 0;
}
