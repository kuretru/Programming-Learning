#include <algorithm>
#include <iostream>
#include <vector>
typedef unsigned char byte;
struct question
{
    int score;
    byte correct;
    std::vector<int> times;
    bool operator<(const question x) const
    {
        int a = *std::max_element(this->times.begin(), this->times.end());
        int b = *std::max_element(x.times.begin(), x.times.end());
        return a < b;
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
    std::vector<question> qList;
    int N, M, x, y;
    std::cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        question q;
        std::cin >> q.score >> x >> y;
        while (x--)
            q.times.push_back(0);
        q.correct = input(y);
        qList.push_back(q);
    }
    while (N--)
    {
        float sum = 0;
        for (int i = 0; i < M; i++)
        {
            char c;
            while ((c = getchar()) != '(')
                ;
            std::cin >> y;
            byte answer = input(y);
            byte b = answer ^ qList[i].correct;
            if (b == 0) //全对
                sum += qList[i].score;
            else if ((answer | qList[i].correct) == qList[i].correct) //没有选错
                sum += qList[i].score / 2.0;
            for (int j = 0; b > 0; j++)
            {
                if ((b & 1) == 1)
                    qList[i].times[j]++;
                b >>= 1;
            }
        }
        printf("%.1f\n", sum);
    }
    auto iter = std::max_element(qList.begin(), qList.end());
    int max = *std::max_element(iter->times.begin(), iter->times.end());
    if (max == 0)
        std::cout << "Too simple" << std::endl;
    else
    {
        for (int i = 0; i < qList.size(); i++)
            for (int j = 0; j < qList[i].times.size(); j++)
                if (qList[i].times[j] == max)
                    printf("%d %d-%c\n", max, i + 1, j + 'a');
    }
    return 0;
}
