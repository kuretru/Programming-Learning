#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool contains(vector<string> list, string key)
{
    vector<string>::iterator iter;
    for (iter = list.begin(); iter != list.end(); iter++)
        if (*iter == key)
            return true;
    return false;
}
int main()
{
    vector<string> names, winner;
    vector<string>::iterator iter;
    string text;
    int M, N, S;
    cin >> M >> N >> S;
    for (int i = 0; i < M; i++)
    {
        cin >> text;
        names.push_back(text);
    }
    for (int i = S - 1; i < M; i += N)
    {
        while (i < M && contains(winner, names[i]))
            i++;
        winner.push_back(names[i]);
    }
    for (iter = winner.begin(); iter != winner.end(); iter++)
        cout << *iter << endl;
    if (S > M)
        cout << "Keep going..." << endl;
    return 0;
}
