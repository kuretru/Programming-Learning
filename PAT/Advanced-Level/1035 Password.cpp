#include <iostream>
#include <string>
#include <vector>

struct account
{
    std::string username = "";
    std::string password = "";
};

const char map[][2] = {{'1', '@'}, {'0', '%'}, {'l', 'L'}, {'O', 'o'}};

int main()
{
    std::vector<account> data;
    int N = 0;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        bool flag = false;
        account a;
        std::cin >> a.username >> a.password;
        for (int j = 0; j < a.password.length(); j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (a.password[j] == map[k][0])
                {
                    a.password[j] = map[k][1];
                    flag = true;
                }
            }
        }
        if (flag)
            data.push_back(a);
    }
    if (data.size() == 0 && N == 1)
        std::cout << "There is 1 account and no account is modified" << std::endl;
    else if (data.size() == 0 && N > 1)
        std::cout << "There are " << N << " accounts and no account is modified" << std::endl;
    else
    {
        std::cout << data.size() << std::endl;
        for (auto iter = data.begin(); iter != data.end(); iter++)
            std::cout << iter->username << " " << iter->password << std::endl;
    }
    return 0;
}
