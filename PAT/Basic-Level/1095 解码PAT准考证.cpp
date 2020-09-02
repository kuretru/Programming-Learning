#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

struct testee
{
    std::string card = "";
    int score = 0;
    int level = 0;
    int site = 0;
    int date = 0;
    testee(std::string card, int score)
    {
        this->card = card;
        this->score = score;
        this->level = card[0] - 'A';
        this->site = std::stoi(card.substr(1, 3));
        this->date = std::stoi(card.substr(4, 6));
    }
    bool operator<(const testee &y) const
    {
        if (score != y.score)
            return score > y.score;
        return card < y.card;
    }
};

struct sitee
{
    int id = 0;
    int count = 0;
    sitee(int id, int count)
    {
        this->id = id;
        this->count = count;
    }
    bool operator<(const sitee &y) const
    {
        if (count != y.count)
            return count > y.count;
        return id < y.id;
    }
};

void type1Handler(unordered_map<int, vector<testee>> &data, std::string param);
void type2Handler(unordered_map<int, vector<testee>> &data, std::string param);
void type3Handler(unordered_map<int, vector<testee>> &data, std::string param);
typedef void (*typeInterface)(unordered_map<int, vector<testee>> &data, std::string param);
typeInterface typeHandler[] = {type1Handler, type2Handler, type3Handler};

unordered_map<int, unordered_map<int, int>> data3;

int main()
{
    std::ios::sync_with_stdio(false);
    int N = 0, M = 0;
    std::cin >> N >> M;
    unordered_map<int, vector<testee>> data[3];
    for (int i = 0; i < N; i++)
    {
        std::string card = "";
        int score = 0;
        std::cin >> card >> score;
        testee t(card, score);
        data[0][t.level].push_back(t);
        data[1][t.site].push_back(t);
        data3[t.date][t.site]++;
    }
    for (int i = 1; i <= M; i++)
    {
        int type = 0;
        std::string param = "";
        std::cin >> type >> param;
        std::cout << "Case " << i << ": " << type << " " << param << std::endl;
        typeHandler[type - 1](data[type - 1], param);
    }
    return 0;
}

void type1Handler(unordered_map<int, vector<testee>> &data, std::string param)
{
    int level = param[0] - 'A';
    if (!data.count(level))
    {
        std::cout << "NA" << std::endl;
        return;
    }
    std::sort(data[level].begin(), data[level].end());
    for (testee t : data[level])
        std::cout << t.card << " " << t.score << std::endl;
}

void type2Handler(unordered_map<int, vector<testee>> &data, std::string param)
{
    int sum = 0, site = std::stoi(param);
    if (!data.count(site))
    {
        std::cout << "NA" << std::endl;
        return;
    }
    for (testee t : data[site])
        sum += t.score;
    std::cout << data[site].size() << " " << sum << std::endl;
}

void type3Handler(unordered_map<int, vector<testee>> &data, std::string param)
{
    int date = std::stoi(param);
    if (!data3.count(date))
    {
        std::cout << "NA" << std::endl;
        return;
    }
    vector<sitee> result;
    for (auto pair : data3[date])
        result.push_back(sitee(pair.first, pair.second));
    std::sort(result.begin(), result.end());
    for (sitee s : result)
        std::cout << s.id << " " << s.count << std::endl;
}
