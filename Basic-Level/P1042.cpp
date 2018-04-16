#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    map<char, int> data;
    map<char, int>::iterator iter;
    string text;
    getline(cin, text);
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] += 32;
        if (text[i] < 'a' || text[i] > 'z')
            continue;
        data[text[i]]++;
    }
    char max = data.begin()->first;
    for (iter = data.begin(); iter != data.end(); iter++)
    {
        if (iter->second > data[max])
            max = iter->first;
    }
    printf("%c %d\n", max, data[max]);
    return 0;
}
