#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct pair
{
    std::vector<int> post;
    std::vector<int> in;
};

int main()
{
    int N = 0, tmp = 0;
    pair raw;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> tmp;
        raw.post.push_back(tmp);
    }
    for (int i = 0; i < N; i++)
    {
        std::cin >> tmp;
        raw.in.push_back(tmp);
    }
    std::queue<pair> q;
    q.push(raw);
    while (!q.empty())
    {
        pair p = q.front();
        q.pop();
        int key = p.post.back();
        int index = std::distance(p.in.begin(), std::find(p.in.begin(), p.in.end(), key));
        if (p.in.front() != key)
        {
            pair left = {
                .post = std::vector<int>(p.post.begin(), p.post.begin() + index),
                .in = std::vector<int>(p.in.begin(), p.in.begin() + index)};
            q.push(left);
        }
        if (p.in.back() != key)
        {
            pair right;
            right.post.assign(p.post.begin() + index, p.post.end() - 1);
            right.in.assign(p.in.begin() + index + 1, p.in.end());
            q.push(right);
        }
        std::cout << key << (q.empty() ? "\n" : " ");
    }
    return 0;
}
