#include <iostream>
#include <map>
#include <string>

int main()
{
    int N;
    std::cin >> N;
    std::map<std::string, std::string> data;
    while (N--)
    {
        char command;
        std::string username, password;
        std::cin >> command >> username >> password;
        if (command == 'N')
        {
            if (data.count(username))
                std::cout << "ERROR: Exist" << std::endl;
            else
            {
                std::cout << "New: OK" << std::endl;
                data[username] = password;
            }
        }
        else
        {
            if (!data.count(username))
                std::cout << "ERROR: Not Exist" << std::endl;
            else if (data[username] == password)
                std::cout << "Login: OK" << std::endl;
            else
                std::cout << "ERROR: Wrong PW" << std::endl;
        }
    }
    return 0;
}
