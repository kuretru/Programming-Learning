#include <iostream>
#include <vector>

int solve(std::vector<int> &data)
{
    bool max = false, min = false;
    int N = data.size() - 1;
    int length = N >> 1;
    for (int i = 1; i <= length; i++)
    {
        if (data[i * 2] <= data[i] && (i * 2 + 1 > N || data[i * 2 + 1] <= data[i]))
            max = true;
        else if (data[i * 2] >= data[i] && (i * 2 + 1 > N || data[i * 2 + 1] >= data[i]))
            min = true;
        else
            return 0;
    }
    if (max && min)
        return 0;
    return max ? 1 : -1;
}

void postOrder(std::vector<int> &result, std::vector<int> &data, int index)
{
    if (index >= data.size())
        return;
    postOrder(result, data, index * 2);
    postOrder(result, data, index * 2 + 1);
    result.push_back(data[index]);
}

int main()
{
    int M = 0, N = 0;
    std::cin >> M >> N;
    std::vector<int> data(N + 1);
    while (M--)
    {
        for (int i = 1; i <= N; i++)
            std::cin >> data[i];
        int heapType = solve(data);
        if (heapType == 1)
            std::cout << "Max Heap" << std::endl;
        else if (heapType == -1)
            std::cout << "Min Heap" << std::endl;
        else
            std::cout << "Not Heap" << std::endl;
        std::vector<int> result;
        postOrder(result, data, 1);
        for (auto iter = result.begin(); iter != result.end(); iter++)
            std::cout << *iter << (iter != result.end() - 1 ? " " : "\n");
    }
    return 0;
}
