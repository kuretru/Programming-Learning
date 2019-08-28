#include <iostream>
#include <map>
#include <set>

struct number
{
    int value = 0;
    int count = 1;
    bool operator<(const number &y) const
    {
        if (count != y.count)
            return count > y.count;
        return value < y.value;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    int N = 0, K = 0;
    std::cin >> N >> K;
    std::set<number> sequence;
    std::map<int, number> data;
    while (N--)
    {
        number n;
        auto iter = sequence.begin(), index = sequence.end();
        std::cin >> n.value;
        if (!sequence.empty())
        {
            std::cout << n.value << ":";
            for (int i = 0; i < K && iter != sequence.end(); i++, iter++)
                std::cout << " " << iter->value;
            std::cout << std::endl;
        }
        if (data.count(n.value))
        {
            sequence.erase(data[n.value]);
            data[n.value].count++;
            n = data[n.value];
        }
        else
            data[n.value] = n;
        sequence.insert(n);
    }
    return 0;
}
