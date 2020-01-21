#include <iostream>
#include <string>

int main()
{
    static std::string data[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::string number;
    std::cin >> number;
    int sum = 0;
    for (int i = 0; i < number.length(); i++)
        sum += number[i] - '0';
    number = std::to_string(sum);
    for (int i = 0; i < number.length(); i++)
        std::cout << data[number[i] - '0'] << (i != number.length() - 1 ? " " : "\n");
    return 0;
}
