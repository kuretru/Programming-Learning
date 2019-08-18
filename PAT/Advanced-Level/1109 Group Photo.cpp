#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct student
{
    std::string name;
    int height;
    bool operator<(const student &y) const
    {
        if (height != y.height)
            return height > y.height;
        return name < y.name;
    }
};

int main()
{
    int N, K, index = 0;
    std::cin >> N >> K;
    std::vector<student> data(N);
    for (int i = 0; i < N; i++)
        std::cin >> data[i].name >> data[i].height;
    std::sort(data.begin(), data.end());
    int rowCount = N / K;
    for (int i = 0; i < K; i++)
    {
        int m = i != 0 ? rowCount : N - (K - 1) * rowCount;
        int mid = (m >> 1) + 1;
        std::vector<std::string> students(m + 1);
        students[mid] = data[index].name;
        for (int j = mid - 1, k = 1; j >= 1; j--, k += 2)
            students[j] = data[index + k].name;
        for (int j = mid + 1, k = 2; j <= m; j++, k += 2)
            students[j] = data[index + k].name;
        index += m;
        for (auto iter = students.begin() + 1; iter != students.end(); iter++)
            std::cout << *iter << (iter != students.end() - 1 ? " " : "\n");
    }
    return 0;
}
