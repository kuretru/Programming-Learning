#include <iostream>
#include <set>
#include <vector>

bool hamiltonian_cycle(std::vector<std::vector<int>> data, std::vector<int> sequence)
{
    if (sequence.size() != data.size())
        return false;
    if (sequence.front() != sequence.back())
        return false;
    std::set<int> vertices;
    for (unsigned int i = 1; i < sequence.size(); i++)
    {
        if (data[sequence[i - 1]][sequence[i]] == 0)
            return false;
        vertices.insert(sequence[i]);
    }
    if (vertices.size() != data.size() - 1)
        return false;
    return true;
}

int main()
{
    int N = 0, M = 0, K = 0;
    std::cin >> N >> M;
    std::vector<std::vector<int>> data(N + 1, std::vector<int>(N + 1, 0));
    while (M--)
    {
        int x = 0, y = 0;
        std::cin >> x >> y;
        data[x][y] = data[y][x] = 1;
    }
    std::cin >> K;
    while (K--)
    {
        int count = 0;
        std::cin >> count;
        std::vector<int> sequence(count);
        for (int i = 0; i < count; i++)
            std::cin >> sequence[i];
        bool result = hamiltonian_cycle(data, sequence);
        std::cout << (result ? "YES" : "NO") << std::endl;
    }
    return 0;
}
