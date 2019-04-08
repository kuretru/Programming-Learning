#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<string, int> data;
    int count;
    cin >> count;
    while (count--)
    {
        string a, b;
        cin >> a >> b;
        data[a + b]++;
    }
    int a = data["CJ"] + data["JB"] + data["BC"];
    int b = data["CC"] + data["JJ"] + data["BB"];
    int c = data["JC"] + data["BJ"] + data["CB"];
    printf("%d %d %d\n", a, b, c);
    printf("%d %d %d\n", c, b, a);
    cout << (data["BC"] >= data["CJ"] && data["BC"] >= data["JB"] ? "B" :
                (data["CJ"] >= data["JB"] ? "C" : "J")) << " " <<
                (data["CB"] >= data["JC"] && data["CB"] >= data["BJ"] ? "B" :
                (data["JC"] >= data["BJ"] ? "C" : "J"));
    return 0;
}
