#include <iostream>
#include <vector>
int main()
{
    int N, b;
    std::cin >> N >> b;
    std::vector<int> digits;
    if (N == 0)
        digits.push_back(0);
    while (N > 0)
    {
        digits.push_back(N % b);
        N /= b;
    }
    std::vector<int>::iterator i;
    std::vector<int>::reverse_iterator j;
    for (i = digits.begin(), j = digits.rbegin(); i != digits.end(); i++, j++)
    {
        if (*i != *j)
        {
            b = 0;
            break;
        }
    }
    std::cout << (b == 0 ? "No" : "Yes") << std::endl;
    for (j = digits.rbegin(); j != digits.rend(); j++)
    {
        if (j != digits.rbegin())
            std::cout << " ";
        std::cout << *j;
    }
    std::cout << std::endl;
    return 0;
}
