#include <iostream>
#include <string>
#include <vector>

int main()
{
    int N = 0;
    scanf("%d\n", &N);
    std::vector<std::string> data(N);
    for (int i = 0; i < N; i++)
        std::getline(std::cin, data[i]);
    std::string result = "";
    for (int i = 1;; i++)
    {
        if (i > data[0].size())
            goto finish;
        char c = data[0][data[0].size() - i];
        for (int j = 1; j < N; j++)
            if (i > data[j].size() || data[j][data[j].size() - i] != c)
                goto finish;
        result = c + result;
    }
finish:
    std::cout << (result == "" ? "nai" : result) << std::endl;
    return 0;
}
