#include <iostream>
#include <string>
#include <vector>

const int SIZE = 54;
const std::string TEXT[] = {"", "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13", "J1", "J2"};

int main()
{
    std::vector<int> data(SIZE + 1), shuffling(SIZE + 1), tmp(SIZE + 1);
    int count = 0;
    std::cin >> count;
    for (int i = 1; i <= SIZE; i++)
    {
        std::cin >> shuffling[i];
        data[i] = i;
    }
    while (count--)
    {
        for (int i = 1; i <= SIZE; i++)
            tmp[shuffling[i]] = data[i];
        data = tmp;
    }
    for (auto iter = data.begin() + 1; iter != data.end(); iter++)
        std::cout << TEXT[*iter] << (iter != data.end() - 1 ? " " : "\n");
    return 0;
}
