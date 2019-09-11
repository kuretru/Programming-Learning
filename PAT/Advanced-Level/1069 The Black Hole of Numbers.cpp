#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

vector<int> int_to_vector(int number)
{
    vector<int> result(4);
    for (int i = 0; i < 4; i++, number /= 10)
        result[i] = number % 10;
    std::sort(result.rbegin(), result.rend());
    return result;
}

int vector_to_int(vector<int> number)
{
    return number[0] * 1000 + number[1] * 100 + number[2] * 10 + number[3];
}

int main()
{
    int N = 0;
    std::cin >> N;
    do
    {
        vector<int> list = int_to_vector(N);
        int first = vector_to_int(list);
        std::reverse(list.begin(), list.end());
        int second = vector_to_int(list);
        N = first - second;
        printf("%04d - %04d = %04d\n", first, second, N);
    } while (N != 0 && N != 6174);
    return 0;
}
