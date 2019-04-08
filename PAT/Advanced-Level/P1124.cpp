#include <iostream>
#include <set>
#include <string>
#include <vector>
int main()
{
    bool keepgoing = true;
    int M, N, S;
    std::cin >> M >> N >> S;
    std::vector<std::string> data(M);
    std::set<std::string> found;
    for (int i = 0; i < M; i++)
        std::cin >> data[i];
    for (int i = S - 1; i < M; i += N)
    {
        while (i >= M || found.find(data[i]) != found.end())
            i++;
        if (i < M)
        {
            std::cout << data[i] << std::endl;
            found.insert(data[i]);
            keepgoing = false;
        }
    }
    if (keepgoing)
        std::cout << "Keep going..." << std::endl;
    return 0;
}
