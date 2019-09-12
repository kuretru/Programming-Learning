#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int N = 0, K = 0;
    scanf("%d %d", &N, &K);
    std::vector<std::vector<std::string>> data(K + 1);
    while (N--)
    {
        char name[5];
        int count = 0, course = 0;
        scanf("%s %d", name, &count);
        while (count--)
        {
            std::cin >> course;
            data[course].push_back(name);
        }
    }
    for (int i = 1; i <= K; i++)
    {
        std::sort(data[i].begin(), data[i].end());
        printf("%d %d\n", i, (int)data[i].size());
        for (std::string name : data[i])
            puts(name.data());
    }
    return 0;
}
