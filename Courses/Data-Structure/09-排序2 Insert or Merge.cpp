#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> insertion_sort(std::vector<int> data, std::vector<int> sequence)
{
    bool found = false;
    for (int i = 2; i <= data.size(); i++)
    {
        std::sort(data.begin(), data.begin() + i);
        if (found)
            return data;
        if (data == sequence)
            found = true;
    }
    return std::vector<int>();
}

std::vector<int> merge_sort(std::vector<int> data, std::vector<int> sequence)
{
    bool found = false;
    for (int i = 2; i <= data.size(); i <<= 1)
    {
        for (int j = 0; j < data.size(); j += i)
        {
            int end = i + j > data.size() ? data.size() : i + j;
            std::sort(data.begin() + j, data.begin() + end);
        }
        if (found)
            return data;
        if (data == sequence)
            found = true;
    }
    return std::vector<int>();
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> data(N), sequence(N);
    for (int i = 0; i < N; i++)
        std::cin >> data[i];
    for (int i = 0; i < N; i++)
        std::cin >> sequence[i];

    std::vector<int> result = insertion_sort(data, sequence);
    std::cout << (result.size() != 0 ? "Insertion Sort" : "Merge Sort") << std::endl;
    if (result.size() == 0)
        result = merge_sort(data, sequence);
    for (auto iter = result.begin(); iter != result.end(); iter++)
        std::cout << *iter << (iter != result.end() - 1 ? " " : "\n");
    return 0;
}
