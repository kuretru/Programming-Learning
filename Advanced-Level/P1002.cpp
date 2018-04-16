#include <iostream>
#include <vector>
using namespace std;
struct term
{
    int exponent;
    float coefficient;
};
int main()
{
    vector<term> data[2], result;
    int count, j, k;
    for (int i = 0; i < 2; i++)
    {
        cin >> count;
        while (count-- > 0)
        {
            term t;
            cin >> t.exponent >> t.coefficient;
            data[i].push_back(t);
        }
    }
    for (j = 0, k = 0; j < data[0].size() && k < data[1].size();)
    {
        if (data[0][j].exponent > data[1][k].exponent)
            result.push_back(data[0][j++]);
        else if (data[0][j].exponent < data[1][k].exponent)
            result.push_back(data[1][k++]);
        else
        {
            if (data[0][j].coefficient + data[1][k].coefficient != 0)
            {
                term t;
                t.exponent = data[0][j].exponent;
                t.coefficient = data[0][j].coefficient + data[1][k].coefficient;
                result.push_back(t);
            }
            j++;
            k++;
        }
    }
    while (j < data[0].size())
        result.push_back(data[0][j++]);
    while (k < data[1].size())
        result.push_back(data[1][k++]);
    cout << result.size();
    for (int i = 0; i < result.size(); i++)
        printf(" %d %.1f", result[i].exponent, result[i].coefficient);
    return 0;
}
