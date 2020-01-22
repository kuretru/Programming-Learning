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
    std::vector<float> tmp(data[0][0].exponent + data[1][0].exponent + 1);
    for (int i = 0; i < data[0].size(); i++)
        for (int j = 0; j < data[1].size(); j++)
            tmp[data[0][i].exponent + data[1][j].exponent] += data[0][i].coefficient * data[1][j].coefficient;
    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        if (tmp[i] == 0)
            continue;
        term t;
        t.exponent = i;
        t.coefficient = tmp[i];
        result.push_back(t);
    }
    std::cout << result.size();
    for (int i = 0; i < result.size(); i++)
        printf(" %d %.1f", result[i].exponent, result[i].coefficient);
    return 0;
}
