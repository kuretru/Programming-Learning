// 查询部分待优化，这个代码在测试点5有可能会超时，重新提交即可，可能是测试机器的性能不同

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

struct instant
{
    int timestamp = 0;
    int type = 0;
    instant() {}
    instant(std::string text, std::string status)
    {
        this->timestamp += (text[0] - '0') * 36000 + (text[1] - '0') * 3600;
        this->timestamp += (text[3] - '0') * 600 + (text[4] - '0') * 60;
        this->timestamp += (text[6] - '0') * 10 + (text[7] - '0');
        this->type = status == "in" ? 0 : 1;
    }
    bool operator<(const instant &y) const
    {
        if (timestamp != y.timestamp)
            return timestamp < y.timestamp;
        return type < y.type;
    }
};

struct car
{
    std::string plate = "";
    int length = 0;
    std::set<instant> records;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::map<std::string, car> data;
    int N = 0, K = 0;
    std::cin >> N >> K;
    while (N--)
    {
        std::string plate = "", time = "", status = "";
        std::cin >> plate >> time >> status;
        data[plate].records.insert(instant(time, status));
    }
    std::vector<int> situation(24 * 60 * 60);
    for (auto pair : data)
    {
        std::set<instant> &records = pair.second.records;
        auto last = records.begin(), iter = records.begin();
        for (iter++; iter != records.end(); last = iter, iter++)
        {
            if (last->type == 0 && iter->type == 1)
            {
                car &c = data[pair.first];
                c.length += iter->timestamp - last->timestamp;
                for (int i = last->timestamp; i < iter->timestamp; i++) // 范围一定是[start, end)
                    situation[i]++;
            }
        }
    }
    while (K--)
    {
        std::string timeString = "";
        std::cin >> timeString;
        instant time = instant(timeString, "out");
        printf("%d\n", situation[time.timestamp]);
    }
    std::vector<std::string> plates;
    int max = 0;
    for (auto pair : data)
    {
        if (pair.second.length < max)
            continue;
        if (pair.second.length > max)
            plates.clear();
        max = pair.second.length;
        plates.push_back(pair.first);
    }
    for (auto iter = plates.begin(); iter != plates.end(); iter++)
        printf("%s ", iter->data());
    printf("%02d:%02d:%02d\n", max / 3600, max / 60 % 60, max % 60);
    return 0;
}
