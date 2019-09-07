#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

struct student
{
    int id = 0;
    int Ge = 0;
    int Gi = 0;
    int final = 0;
    std::vector<int> choices;
    void init(int id, int K)
    {
        this->id = id;
        this->final = this->Ge + this->Gi;
        this->choices.resize(K);
    }
    bool operator<(const student &y) const
    {
        if (final != y.final)
            return final > y.final;
        return Ge > y.Ge;
    }
};

struct school
{
    int quota = 0;
    std::set<int> students;
};

int main()
{
    int N = 0, M = 0, K = 0;
    std::cin >> N >> M >> K;
    std::vector<school> schools(M);
    for (int i = 0; i < M; i++)
        std::cin >> schools[i].quota;
    std::vector<student> data(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> data[i].Ge >> data[i].Gi;
        data[i].init(i, K);
        for (int j = 0; j < K; j++)
            std::cin >> data[i].choices[j];
    }
    std::sort(data.begin(), data.end());
    int lastAdmit = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j : data[i].choices)
        {
            if (schools[j].students.size() < schools[j].quota)
            {
                schools[j].students.insert(data[i].id);
                lastAdmit = j;
                break;
            }
            else if (data[i].final == data[i - 1].final && data[i].Ge == data[i - 1].Ge)
            {
                if (j == lastAdmit)
                {
                    schools[j].students.insert(data[i].id);
                    break;
                }
            }
        }
    }
    for (school s : schools)
    {
        for (auto iter = s.students.begin(); iter != s.students.end(); iter++)
            std::cout << (iter != s.students.begin() ? " " : "") << *iter;
        std::cout << std::endl;
    }
    return 0;
}
