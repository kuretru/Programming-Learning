#include <iostream>
#include <string>

struct player
{
    std::string name = "";
    int score = 0;
};

int main()
{
    int count = 0;
    player max, min;
    max.score = INT32_MAX;
    min.score = 0;
    std::cin >> count;
    while (count--)
    {
        player p;
        int a, b;
        std::cin >> p.name >> a >> b;
        p.score = a * a + b * b;
        if (p.score < max.score)
            max = p;
        if (p.score > min.score)
            min = p;
    }
    std::cout << max.name << " " << min.name << std::endl;
    return 0;
}
