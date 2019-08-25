#include <iostream>
#include <set>
#include <string>
#include <vector>

int main()
{
    int M = 0, N = 0, S = 0;
    std::cin >> M >> N >> S;
    std::vector<std::string> data(M + 1);
    std::set<std::string> found;
    for (int i = 1; i <= M; i++)
        std::cin >> data[i];
    bool keepgoing = true;
    for (int i = S; i <= M; i += N)
    {
        while (i > M || found.count(data[i]))
            i++;
        if (i <= M)
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
