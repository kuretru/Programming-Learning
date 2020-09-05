#include <algorithm>
#include <cstdio>
#include <vector>

const int open_time = 8 * 60 * 60;
const int close_time = 21 * 60 * 60;

struct player
{
    int arrivingTime = 0;
    int playingTime = 0;
    bool isVip = false;
    bool operator<(const player &y) const
    {
        return arrivingTime < y.arrivingTime;
    }
};

struct table
{
    int leftTime = 0;
    int servedTime = 0;
    int servedCount = 0;
    bool vip = false;
};

int get_vip_table(std::vector<table> &tables, int M)
{
    for (int i = 1; i <= M; i++)
        if (!tables[i].leftTime && tables[i].vip)
            return i;
    return -1;
}

int get_vip_player(std::vector<player> &data, int time)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (time < data[i].arrivingTime)
            break;
        if (data[i].isVip)
            return i;
    }
    return -1;
}

void assign(player &player, table &table, int time)
{
    table.leftTime = player.playingTime;
    table.servedTime += player.playingTime;
    table.servedCount++;
    printf("%02d:%02d:%02d ", player.arrivingTime / 3600, player.arrivingTime / 60 % 60, player.arrivingTime % 60);
    printf("%02d:%02d:%02d ", time / 3600, time / 60 % 60, time % 60);
    printf("%d\n", (int)((time - player.arrivingTime) / 60.0 + 0.5));
}

int main()
{
    int N = 0, M = 0, K = 0, tmp = 0;
    scanf("%d", &N);
    std::vector<player> data(N);
    for (int i = 0; i < N; i++)
    {
        int hour = 0, minute = 0, second = 0, vip = 0;
        scanf("%d:%d:%d %d %d", &hour, &minute, &second, &data[i].playingTime, &vip);
        data[i].arrivingTime = hour * 3600 + minute * 60 + second;
        // 注意点：有测试数据含有玩2个小时以上的客人
        data[i].playingTime = data[i].playingTime > 120 ? 7200 : data[i].playingTime * 60;
        data[i].isVip = vip == 1;
    }
    scanf("%d %d", &M, &K);
    std::vector<table> tables(M + 1);
    while (K--)
    {
        scanf("%d", &tmp);
        tables[tmp].vip = true;
    }
    std::sort(data.begin(), data.end());
    for (int i = open_time; i < close_time; i++)
    {
        if (data.empty())
            break;
        for (int j = 1; j <= M; j++)
            if (tables[j].leftTime > 0)
                tables[j].leftTime--;
        if (i < data.front().arrivingTime)
            continue;

        // 先把VIP会员分配到VIP桌
        for (int j = get_vip_table(tables, M); j > 0; j = get_vip_table(tables, M))
        {
            if (data.empty() || i < data.front().arrivingTime)
                break;
            int vip = get_vip_player(data, i);
            if (vip == -1)
                break;
            assign(data[vip], tables[j], i);
            data.erase(data.begin() + vip);
        }

        // 剩下的按顺序分配，即使还有VIP会员也分配到普通桌；普通会员也可以分配到VIP桌
        for (int j = 1; j <= M; j++)
        {
            if (data.empty() || i < data.front().arrivingTime)
                break;
            if (tables[j].leftTime)
                continue;
            assign(data.front(), tables[j], i);
            data.erase(data.begin());
        }
    }
    for (auto iter = tables.begin() + 1; iter != tables.end(); iter++)
        printf("%d%c", iter->servedCount, iter != tables.end() - 1 ? ' ' : '\n');
    return 0;
}
