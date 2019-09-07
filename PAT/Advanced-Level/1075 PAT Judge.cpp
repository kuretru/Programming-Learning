#include <algorithm>
#include <iostream>
#include <vector>

struct student
{
    int rank = 0;
    int id = 0;
    int total = -1;
    int count = 0;
    std::vector<int> scores;
    bool show = false;
    student()
    {
        scores.resize(6, -1);
    }
    bool operator<(const student &y) const
    {
        if (total != y.total)
            return total > y.total;
        if (count != y.count)
            return count > y.count;
        return id < y.id;
    }
};

int main()
{
    int N = 0, K = 0, M = 0;
    std::cin >> N >> K >> M;
    std::vector<int> perfect(K + 1);
    for (int i = 1; i <= K; i++)
        std::cin >> perfect[i];
    std::vector<student> data(N + 1);
    while (M--)
    {
        int user = 0, problem = 0, partial = 0;
        std::cin >> user >> problem >> partial;
        data[user].id = user;
        if (!data[user].show && partial > -1)
            data[user].show = true;
        if (partial == -1)
            partial = 0;
        if (partial > data[user].scores[problem])
        {
            if (data[user].total == -1)
                data[user].total = partial;
            else if (data[user].scores[problem] == -1)
                data[user].total += partial;
            else
                data[user].total += partial - data[user].scores[problem];
            data[user].scores[problem] = partial;
            if (partial == perfect[problem])
                data[user].count++;
        }
    }
    std::sort(data.begin() + 1, data.end());
    for (int i = 1; i <= N && data[i].show; i++)
    {
        if (data[i].total == data[i - 1].total)
            data[i].rank = data[i - 1].rank;
        else
            data[i].rank = i;
    }
    for (int i = 1; i <= N && data[i].show; i++)
    {
        printf("%d %05d %d", data[i].rank, data[i].id, data[i].total);
        for (int j = 1; j <= K; j++)
        {
            if (data[i].scores[j] == -1)
                std::cout << " -";
            else
                std::cout << " " << data[i].scores[j];
        }
        std::cout << std::endl;
    }
    return 0;
}
