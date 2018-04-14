#include <iostream>
#include <string>
using namespace std;
int main()
{
    string data, table[10] = {"ling", "yi", "er", "san", "si",
                              "wu", "liu", "qi", "ba", "jiu"};
    cin >> data;
    int sum = 0;
    for (unsigned int i = 0; i < data.length(); i++)
        sum += data[i] - '0';
    data = to_string(sum);
    for (unsigned int i = 0; i < data.length(); i++)
        cout << table[data[i] - '0'] << (i != data.length() - 1 ? " " : "\n");
    return 0;
}
