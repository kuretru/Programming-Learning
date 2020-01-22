#include <iostream>
#include <vector>

struct term
{
    int exponent = 0;
    float coefficient = 0;
};

int main()
{
    std::vector<term> data[2], result;
    int count = 0;
    for (int i = 0; i < 2; i++)
    {
        std::cin >> count;
        data[i].resize(count);
        for (int j = 0; j < count; j++)
            std::cin >> data[i][j].exponent >> data[i][j].coefficient;
    }
    int j = 0, k = 0;
    for (; j < data[0].size() && k < data[1].size();)
    {
        if (data[0][j].exponent > data[1][k].exponent)
            result.push_back(data[0][j++]);
        else if (data[0][j].exponent < data[1][k].exponent)
            result.push_back(data[1][k++]);
        else
        {
            if (data[0][j].coefficient + data[1][k].coefficient != 0)
            {
                data[0][j].coefficient += data[1][k].coefficient;
                result.push_back(data[0][j]);
            }
            j++;
            k++;
        }
    }
    while (j < data[0].size())
        result.push_back(data[0][j++]);
    while (k < data[1].size())
        result.push_back(data[1][k++]);
    std::cout << result.size();
    for (int i = 0; i < result.size(); i++)
        printf(" %d %.1f", result[i].exponent, result[i].coefficient);
    return 0;
}
