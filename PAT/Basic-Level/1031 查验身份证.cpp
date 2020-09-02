#include <iostream>
#include <string>

const int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
const char digit[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

bool is_valid(std::string id)
{
    int sum = 0;
    for (int i = 0; i < 17; i++)
        sum += (id[i] - '0') * weight[i];
    sum %= 11;
    if (digit[sum] == id[17])
        return true;
    id[17] = digit[sum];
    return false;
}

int main()
{
    int count = 0;
    bool allPassed = true;
    std::cin >> count;
    while (count--)
    {
        std::string id = "";
        std::cin >> id;
        if (is_valid(id))
            continue;
        else if (allPassed)
            allPassed = false;
        std::cout << id << std::endl;
    }
    if (allPassed)
        std::cout << "All passed" << std::endl;
    return 0;
}
