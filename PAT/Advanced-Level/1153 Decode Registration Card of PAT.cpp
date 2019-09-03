#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

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

void type1Handler(std::map<int, std::set<testee>> &data, std::string param);
void type2Handler(std::map<int, std::set<testee>> &data, std::string param);
void type3Handler(std::map<int, std::set<testee>> &data, std::string param);
typedef void (*typeInterface)(std::map<int, std::set<testee>> &data, std::string param);
typeInterface typeHandler[] = {type1Handler, type2Handler, type3Handler};

std::map<int, std::map<int, int>> type3Data;
std::map<int, std::set<sitee>> type3Result;

int main()
{
    int N = 0, M = 0;
    std::cin >> N >> M;
    std::map<int, std::set<testee>> data[3];
    for (int i = 0; i < N; i++)
    {
        std::string card = "";
        int score = 0;
        std::cin >> card >> score;
        testee t(card, score);
        data[0][t.level].insert(t);
        data[1][t.site].insert(t);
        type3Data[t.date][t.site]++;
    }
    for (auto i : type3Data)
        for (auto j : i.second)
            type3Result[i.first].insert(sitee(j.first, j.second));
    for (int i = 1; i <= M; i++)
    {
        int type = 0;
        std::string param = "";
        std::cin >> type >> param;
        std::cout << "Case " << i << ": " << type << " " << param << std::endl;
        if (1 <= type && type <= 3)
            typeHandler[type - 1](data[type - 1], param);
        else
            std::cout << "NA" << std::endl;
    }
    return 0;
}

void type1Handler(std::map<int, std::set<testee>> &data, std::string param)
{
    int level = param[0] - 'A';
    if (data.count(level))
        for (testee t : data[level])
            std::cout << t.card << " " << t.score << std::endl;
    else
        std::cout << "NA" << std::endl;
}

void type2Handler(std::map<int, std::set<testee>> &data, std::string param)
{
    int Nt = 0, Ns = 0, site = std::stoi(param);
    if (data.count(site))
    {
        for (testee t : data[site])
        {
            Nt++;
            Ns += t.score;
        }
        std::cout << Nt << " " << Ns << std::endl;
    }
    else
        std::cout << "NA" << std::endl;
}

void type3Handler(std::map<int, std::set<testee>> &data, std::string param)
{
    int date = std::stoi(param);
    if (type3Data.count(date))
    {
        std::set<sitee> result;
        for (auto pair : type3Data[date])
            result.insert(sitee(pair.first, pair.second));
        for (sitee s : result)
            std::cout << s.id << " " << s.count << std::endl;
    }
    else
        std::cout << "NA" << std::endl;
}
