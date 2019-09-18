#include <iostream>
#include <map>
#include <vector>
struct Monomial
{
    int coef;
    int exp;
};
struct Polynomial
{
    std::vector<Monomial> data;
    int count = 0;
};

Polynomial input()
{
    Polynomial result;
    std::cin >> result.count;
    result.data.resize(result.count);
    for (int i = 0; i < result.count; i++)
        std::cin >> result.data[i].coef >> result.data[i].exp;
    return result;
}

Polynomial multiply(Polynomial X, Polynomial Y)
{
    std::map<int, Monomial> map;
    for (int i = 0; i < X.count; i++)
    {
        for (int j = 0; j < Y.count; j++)
        {
            Monomial m;
            m.coef = X.data[i].coef * Y.data[j].coef;
            m.exp = X.data[i].exp + Y.data[j].exp;
            if (map.count(m.exp))
                map[m.exp].coef += m.coef;
            else
                map[m.exp] = m;
        }
    }
    Polynomial result;
    for (auto iter = map.rbegin(); iter != map.rend(); iter++)
    {
        if (iter->second.coef != 0)
        {
            result.data.push_back(iter->second);
            result.count++;
        }
    }
    return result;
}

Polynomial add(Polynomial X, Polynomial Y)
{
    Polynomial result;
    int i = 0, j = 0;
    while (i < X.count && j < Y.count)
    {
        if (X.data[i].exp > Y.data[j].exp)
            result.data.push_back(X.data[i++]);
        else if (X.data[i].exp < Y.data[j].exp)
            result.data.push_back(Y.data[j++]);
        else
        {
            Monomial m;
            m.exp = X.data[i].exp;
            m.coef = X.data[i++].coef + Y.data[j++].coef;
            result.data.push_back(m);
        }
        result.count++;
    }
    while (i < X.count)
    {
        result.data.push_back(X.data[i++]);
        result.count++;
    }
    while (j < Y.count)
    {
        result.data.push_back(Y.data[j++]);
        result.count++;
    }
    return result;
}

void print(Polynomial P)
{
    bool printed = false;
    for (int i = 0; i < P.count; i++)
    {
        if (P.data[i].coef != 0)
        {
            if (!printed)
                printed = true;
            else
                std::cout << " ";
            std::cout << P.data[i].coef << " " << P.data[i].exp;
        }
    }
    if (!printed)
        std::cout << "0 0";
    std::cout << std::endl;
}

int main()
{
    Polynomial P1 = input();
    Polynomial P2 = input();
    Polynomial product = multiply(P1, P2);
    Polynomial sum = add(P1, P2);
    print(product);
    print(sum);
    return 0;
}
