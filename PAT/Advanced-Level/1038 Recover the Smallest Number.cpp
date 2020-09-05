#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool cmp(std::string &x, std::string &y)
{
    return x + y < y + x;
}

int main()
{
    int N = 0;
    std::cin >> N;
    std::vector<std::string> data(N);
    for (int i = 0; i < N; i++)
        std::cin >> data[i];
    std::sort(data.begin(), data.end(), cmp);
    std::string result = "";
    for (auto iter = data.begin(); iter != data.end(); iter++)
        result += *iter;
    while (!result.empty() && result[0] == '0')
        result.erase(result.begin());
    std::cout << (result.empty() ? "0" : result) << std::endl;
    return 0;
}
