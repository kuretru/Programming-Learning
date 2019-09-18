#include <algorithm>
#include <cstdio>
#include <vector>

struct user
{
    int id = 0;
    int perfectly = 0;
    int score = -1;
    int sumbit = 0;
    std::vector<int> scores;
    user()
    {
        scores.resize(6, -1);
    }
    bool operator<(const user y) const
    {
        if (score != y.score)
            return score > y.score;
        if (perfectly != y.perfectly)
            return perfectly > y.perfectly;
        return id < y.id;
    }
};

int main()
{
    int N, K, M;
    scanf("%d %d %d", &N, &K, &M);
    std::vector<user> users(N + 1);
    std::vector<int> fullMark(K + 1);
    for (int i = 1; i <= K; i++)
        scanf("%d", &fullMark[i]);
    while (M--)
    {
        int user, problem, score;
        scanf("%d %d %d", &user, &problem, &score);
        if (score == -1)
            score = 0;
        else
            users[user].sumbit++;
        users[user].id = user;
        if (score > users[user].scores[problem])
            users[user].scores[problem] = score;
    }
    for (int i = 1; i <= N; i++)
    {
        if (!users[i].sumbit)
            continue;
        users[i].score = 0;
        for (int j = 1; j <= K; j++)
        {
            if (users[i].scores[j] > 0)
                users[i].score += users[i].scores[j];
            if (users[i].scores[j] == fullMark[j])
                users[i].perfectly++;
        }
    }
    std::sort(users.begin() + 1, users.end());
    int lastScore = users[1].score, lastRank = 1;
    for (int i = 1; i <= N; i++)
    {
        if (users[i].score == -1)
            break;
        int rank = users[i].score == lastScore ? lastRank : i;
        lastScore = users[i].score;
        lastRank = rank;
        printf("%d %05d %d", rank, users[i].id, users[i].score);
        for (int j = 1; j <= K; j++)
        {
            if (users[i].scores[j] == -1)
                printf(" -");
            else
                printf(" %d", users[i].scores[j]);
        }
        printf("\n");
    }
    return 0;
}
