#include <algorithm>
#include <iostream>
#include <string>
int main()
{
    int N, M, *banned, people = 0, items = 0;
    std::cin >> N >> M;
    banned = new int[M];
    for (int i = 0; i < M; i++)
        std::cin >> banned[i];
    while (N--)
    {
        std::string name;
        int count, number;
        bool found = false;
        std::cin >> name >> count;
        while (count--)
        {
            std::cin >> number;
            if (std::find(banned, banned + M, number) != banned + M)
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
