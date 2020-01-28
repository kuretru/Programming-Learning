#include <cstdio>
#include <queue>
#include <vector>

const int START_TIME = 8 * 60;
const int END_TIME = 17 * 60;

using std::queue;
using std::vector;

struct customer
{
    int begin = 0;
    int end = 0;
};

void fill_queue(vector<queue<int>> &windows, int &step, int queue_limit, int customer_limit)
{
    for (int full_queue_count = 0;; full_queue_count = 0)
    {
        for (queue<int> &q : windows)
        {
            if (q.size() < queue_limit && step <= customer_limit)
                q.push(step++);
            else
                full_queue_count++;
        }
        if (full_queue_count == windows.size())
            break;
    }
}

int next_customer(vector<queue<int>> &windows, vector<int> &customers)
{
    int min = -1;
    for (queue<int> &q : windows)
    {
        if (q.empty())
            continue;
        if (min == -1 || customers[q.front()] < customers[min])
            min = q.front();
    }
    return min;
}

int main()
{
    int N = 0, M = 0, K = 0, Q = 0, query = 0;
    scanf("%d %d %d %d", &N, &M, &K, &Q);
    vector<int> customers(K + 1);
    vector<customer> result(K + 1);
    for (int i = 1; i <= K; i++)
        scanf("%d", &customers[i]);

    vector<queue<int>> windows(N);
    int step = 1, time = START_TIME;
    while (true)
    {
        fill_queue(windows, step, M, K);
        for (queue<int> &q : windows)
            if (result[q.front()].begin == 0)
                result[q.front()].begin = time;
        int next = next_customer(windows, customers);
        if (next == -1)
            break;
        int spent = customers[next];
        time += spent;
        for (queue<int> &q : windows)
        {
            customers[q.front()] -= spent;
            if (customers[q.front()] == 0)
            {
                result[q.front()].end = time;
                q.pop();
            }
        }
    }

    while (Q--)
    {
        scanf("%d", &query);
        if (result[query].begin >= END_TIME)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n", result[query].end / 60, result[query].end % 60);
    }
    return 0;
}
