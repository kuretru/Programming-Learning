#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int N = 0, M = 0, people = 0, items = 0;
    std::cin >> N >> M;
    std::vector<int> banned(M);
    for (int i = 0; i < M; i++)
        std::cin >> banned[i];
    while (N--)
    {
        std::string name = "";
        int count = 0, number = 0;
        bool found = false;
        std::cin >> name >> count;
        while (count--)
        {
            std::cin >> number;
            if (std::find(banned.begin(), banned.end(), number) != banned.end())
            {
                if (!found)
                {
                    found = true;
                    people++;
                    std::cout << name << ":";
                }
                printf(" %04d", number);
                items++;
            }
        }
        if (found)
            std::cout << std::endl;
    }
    printf("%d %d\n", people, items);
    return 0;
}
