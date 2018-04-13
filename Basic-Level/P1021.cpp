#include <iostream>
#include <string>
int main()
{
    int count[10] = {0};
    std::string number;
    std::cin >> number;
    for (int i = 0; i < (int)number.size(); i++)
        count[number[i] - '0']++;
    for (int i = 0; i < 10; i++)
        if (count[i] > 0)
            std::cout << i << ":" << count[i] << std::endl;
    return 0;
}
