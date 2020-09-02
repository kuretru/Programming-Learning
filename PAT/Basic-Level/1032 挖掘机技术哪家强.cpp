#include <iostream>
#include <map>

int main()
{
    std::map<int, int> data;
    int count = 0;
    std::cin >> count;
    while (count--)
    {
        int number = 0, score = 0;
        std::cin >> number >> score;
        data[number] += score;
    }
    int max = 1;
    for (int i = 2; i <= data.size(); i++)
        if (data[i] > data[max])
            max = i;
    std::cout << max << " " << data[max] << std::endl;
    return 0;
}
