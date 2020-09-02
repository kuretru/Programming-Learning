#include <algorithm>
#include <iostream>
#include <vector>

typedef unsigned char byte;
struct question
{
    int score = 0;
    byte correct = ' ';
    int times = 0;
    bool operator<(const question y) const
    {
        return this->times < y.times;
    }
};

byte input(int count)
{
    byte result = 0;
    while (count--)
    {
        getchar();
        byte t = 1;
        t <<= (getchar() - 'a');
        result |= t;
    }
    return result;
}

int main()
{
    std::vector<question> data;
    int N = 0, M = 0, tmp;
    std::cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        question q;
        std::cin >> q.score >> tmp >> tmp;
        q.correct = input(tmp);
        data.push_back(q);
    }
    while (N--)
    {
        int sum = 0;
        for (int i = 0; i < M; i++)
        {
            char c;
            while ((c = getchar()) != '(')
                ;
            std::cin >> tmp;
            byte answer = input(tmp);
            if ((answer ^ data[i].correct) == 0)
                sum += data[i].score;
            else
                data[i].times++;
        }
        std::cout << sum << std::endl;
    }
    int max = std::max_element(data.begin(), data.end())->times;
    if (max == 0)
        std::cout << "Too simple";
    else
    {
        std::cout << max;
        for (int i = 0; i < data.size(); i++)
            if (data[i].times == max)
                std::cout << " " << i + 1;
    }
    std::cout << std::endl;
    return 0;
}
