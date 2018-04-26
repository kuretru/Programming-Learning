#include <iostream>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int teacher, n, sum = 0, count = 0, max = 0, min = M;
        cin >> teacher;
        for (int j = 1; j < N; j++)
        {
            cin >> n;
            if (n < 0 || n > M)
                continue;
            sum += n;
            if (n > max)
                max = n;
            if (n < min)
                min = n;
            count++;
        }
        sum -= max + min;
        sum = (sum * 1.0 / (count - 2) + teacher) / 2 + 0.5;
        cout << sum << endl;
    }
    return 0;
}
