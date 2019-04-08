#include <cmath>
#include <iostream>
using namespace std;
bool prime(int number)
{
    int end = sqrt(number);
    for (int i = 2; i <= end; i++)
        if (number % i == 0)
            return false;
    return number > 1;
}
int main()
{
    int count = 0, display = 0, begin, end;
    cin >> begin >> end;
    for (int i = 2; count < end; i++)
    {
        if (prime(i))
        {
            count++;
            if (count >= begin)
                cout << i << (display++ % 10 != 9 && count < end ? " " : "\n");
        }
    }
    return 0;
}
