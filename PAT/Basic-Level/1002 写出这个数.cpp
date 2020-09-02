#include <iostream>
#include <string>

const std::string table[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main()
{
    std::string data = "";
    int sum = 0;
    std::cin >> data;
    for (int i = 0; i < data.length(); i++)
        sum += data[i] - '0';
    data = std::to_string(sum);
    for (int i = 0; i < data.length(); i++)
        std::cout << table[data[i] - '0'] << (i != data.length() - 1 ? " " : "\n");
    return 0;
}
