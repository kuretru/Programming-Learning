#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct timee
{
    int hour = 0;
    int minute = 0;
    int second = 0;
    bool operator<(const timee t) const
    {
        if (this->hour != t.hour)
            return this->hour < t.hour;
        if (this->minute != t.minute)
            return this->minute < t.minute;
        return this->second < t.second;
    }
};

struct person
{
    std::string name;
    timee signIn;
    timee signOut;
};

bool cmpIn(const person &x, const person &y)
{
    return x.signIn < y.signIn;
}

bool cmpOut(const person &x, const person &y)
{
    return x.signOut < y.signOut;
}

int main()
{
    std::vector<person> list;
    int count = 0;
    std::cin >> count;
    while (count--)
    {
        person p;
        std::cin >> p.name;
        scanf("%d:%d:%d", &p.signIn.hour, &p.signIn.minute, &p.signIn.second);
        scanf("%d:%d:%d", &p.signOut.hour, &p.signOut.minute, &p.signOut.second);
        list.push_back(p);
    }
    sort(list.begin(), list.end(), cmpIn);
    std::string first = list.front().name;
    sort(list.begin(), list.end(), cmpOut);
    std::string last = list.back().name;
    std::cout << first << " " << last << std::endl;
    return 0;
}
