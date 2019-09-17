#include <algorithm>
#include <iostream>
#include <vector>

const int START_TIME = 8 * 60 * 60;
const int END_TIME = 17 * 60 * 60;

struct person
{
    int arrive_time = 0;
    int processing_time = 0;
    person(int arrive_time, int processing_time)
    {
        this->arrive_time = arrive_time;
        this->processing_time = processing_time;
    }
    bool operator<(const person &y) const
    {
        return arrive_time < y.arrive_time;
    }
};

int main()
{
    int N = 0, K = 0;
    scanf("%d %d", &N, &K);
    std::vector<person> data;
    std::vector<int> windows(K, 0);
    for (int i = 0; i < N; i++)
    {
        int HH = 0, MM = 0, SS = 0, P = 0;
        scanf("%d:%d:%d %d", &HH, &MM, &SS, &P);
        if (HH * 3600 + SS > END_TIME)
            continue;
        data.push_back(person(HH * 3600 + MM * 60 + SS, P * 60));
    }
    std::sort(data.begin(), data.end());
    int result = 0;
    for (int i = 0, j = START_TIME; i < data.size(); j++)
    {
        int idle = -1;
        for (int k = 0; k < K; k++)
        {
            if (windows[k] > 1)
                windows[k]--;
            else if (j >= data[i].arrive_time)
                idle = k;
        }
        if (idle != -1)
        {
            result += j - data[i].arrive_time;
            windows[idle] = data[i++].processing_time;
        }
    }
    printf("%.1lf\n", result / 60.0 / data.size());
    return 0;
}
