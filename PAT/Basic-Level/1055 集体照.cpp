#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct person
{
    std::string name = "";
    int height = 0;
    bool operator<(const person &y)
    {
        if (height != y.height)
            return height > y.height;
        return name < y.name;
    }
};

int main()
{
    int N = 0, K = 0, start = 0;
    std::cin >> N >> K;
    std::vector<int> offset(N);
    for (int i = 0, j = 1; i < N; i++, j = -j)
        offset[i] = j * ((i + 1) / 2);
    std::vector<person> data(N);
    for (int i = 0; i < N; i++)
        std::cin >> data[i].name >> data[i].height;
    std::sort(data.begin(), data.end());
    for (int i = 0; i < K; i++)
    {
        int m = N / K;
        if (i == 0)
            m += N % K;
        int mid = m / 2;
        person *row = new person[m];
        for (int j = 0; j < m; j++)
            row[mid + offset[j]] = data[start++];
        for (int j = 0; j < m; j++)
            std::cout << row[j].name << (j == m - 1 ? "\n" : " ");
    }
    return 0;
}
