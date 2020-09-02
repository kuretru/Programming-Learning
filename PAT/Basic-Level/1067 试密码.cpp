#include <iostream>
#include <string>

int main()
{
    std::string password = "";
    int maxTimes;
    std::cin >> password >> maxTimes;
    getchar();
    while (maxTimes--)
    {
        std::string text;
        getline(std::cin, text);
        if (text == "#")
            return 0;
        if (text == password)
        {
            std::cout << "Welcome in" << std::endl;
            return 0;
        }
        else
            std::cout << "Wrong password: " << text << std::endl;
    }
    std::cout << "Account locked" << std::endl;
    return 0;
}
