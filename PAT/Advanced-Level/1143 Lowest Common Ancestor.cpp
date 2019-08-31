#include <iostream>
#include <set>
#include <vector>

int main()
{
    int M = 0, N = 0;
    std::cin >> M >> N;
    std::set<int> nodes;
    std::vector<int> data(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> data[i];
        nodes.insert(data[i]);
    }
    while (M--)
    {
        int u = 0, v = 0;
        std::cin >> u >> v;
        bool uNotFound = !nodes.count(u), vNotFound = !nodes.count(v);
        if (uNotFound && vNotFound)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if (uNotFound || vNotFound)
            printf("ERROR: %d is not found.\n", uNotFound ? u : v);
        if (uNotFound || vNotFound)
            continue;
        int lca = 0;
        for (int i = 0; i < N; i++)
        {
            if ((u <= data[i] && data[i] <= v) || (u >= data[i] && data[i] >= v))
            {
                lca = data[i];
                break;
            }
        }
        if (lca == u || lca == v)
            printf("%d is an ancestor of %d.\n", lca, lca == u ? v : u);
        else
            printf("LCA of %d and %d is %d.\n", u, v, lca);
    }
    return 0;
}
