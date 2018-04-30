#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int *data = new int[N];
    for (int i = 0; i < N; i++)
        cin >> data[i];
    sort(data, data + N);
    double result = data[0];
    for (int i = 1; i < N; i++)
        result = (result + data[i]) / 2;
    cout << (int)result << endl;
    return 0;
}
