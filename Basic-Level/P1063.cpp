#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int N, a, b;
    cin >> N;
    double *data = new double[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        data[i] = sqrt(a * a + b * b);
    }
    double *max = max_element(data, data + N);
    printf("%.2lf\n", *max);
    return 0;
}
