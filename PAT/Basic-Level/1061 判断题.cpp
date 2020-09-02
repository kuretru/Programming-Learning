#include <iostream>
#include <vector>

struct question
{
    int score = 0;
    int answer = 0;
};

int main()
{
    int N = 0, M = 0;
    std::cin >> N >> M;
    std::vector<question> data(M);
    for (int i = 0; i < M; i++)
        std::cin >> data[i].score;
    for (int i = 0; i < M; i++)
        std::cin >> data[i].answer;
    while (N--)
    {
        int key = 0, result = 0;
        for (int i = 0; i < M; i++)
        {
            std::cin >> key;
            if (key == data[i].answer)
                result += data[i].score;
        }
        std::cout << result << std::endl;
    }
    return 0;
}
