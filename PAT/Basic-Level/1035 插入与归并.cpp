#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

vector<int> insertion(vector<int> data, vector<int> sequence)
{
    bool found = false;
    for (auto iter = data.begin() + 2; iter != data.end(); iter++)
    {
        std::sort(data.begin(), iter);
        if (found)
            return data;
        if (data == sequence)
            found = true;
    }
    return vector<int>();
}

vector<int> merge(vector<int> data, vector<int> sequence)
{
    bool found = false;
    for (int i = 2; i <= data.size(); i = i << 1 > data.size() ? data.size() : i << 1)
    {
        for (int j = 0; j < data.size(); j += i)
            std::sort(data.begin() + j, j + i < data.size() ? data.begin() + j + i : data.end());
        if (found)
            return data;
        if (data == sequence)
            found = true;
    }
    return vector<int>();
}

int main()
{
    int N = 0;
    std::cin >> N;
    vector<int> data(N), sequence(N);
    for (int i = 0; i < N; i++)
        std::cin >> data[i];
    for (int i = 0; i < N; i++)
        std::cin >> sequence[i];
    vector<int> result = insertion(data, sequence);
    std::cout << (result.empty() ? "Merge Sort" : "Insertion Sort") << std::endl;
    if (result.empty())
        result = merge(data, sequence);
    for (auto iter = result.begin(); iter != result.end(); iter++)
        std::cout << *iter << (iter != result.end() - 1 ? " " : "\n");
    return 0;
}
