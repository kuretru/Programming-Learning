#include <iostream>
using namespace std;
int main()
{
    int M, N, A, B, target, t;
    cin >> M >> N >> A >> B >> target;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &t);
            if (t >= A && t <= B)
                t = target;
            printf("%03d%c", t, j != N - 1 ? ' ' : '\n');
        }
    }
    return 0;
}
