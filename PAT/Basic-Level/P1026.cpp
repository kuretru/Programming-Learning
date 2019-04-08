#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int start, end;
    cin >> start >> end;
    int second = (end - start + 50) / 100;
    printf("%02d:%02d:%02d\n", second / 60 / 60, second / 60 % 60, second % 60);
    return 0;
}
