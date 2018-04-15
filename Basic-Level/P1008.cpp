#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, M, t;
    cin >> N >> M;
    vector<int> data;
    for (int i = 0; i < N; i++)
    {
        cin >> t;
        data.push_back(t);
    }
    int end = data.size() - 1;
    for (int i = 0; i < M % N; i++)
    {
        t = data[end];
        for (int j = end; j > 0; j--)
            data[j] = data[j - 1];
        data[0] = t;
    }
    for (int i = 0; i < (int)data.size(); i++)
        cout << data[i] << (i != end ? " " : "\n");
    return 0;
}
