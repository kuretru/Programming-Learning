#include <iostream>
#include <vector>

void print(std::vector<int> &data, int index, int N, std::vector<int> sequence)
{
    sequence.push_back(data[index]);
    if (index * 2 + 1 <= N)
        print(data, index * 2 + 1, N, sequence);
    if (index * 2 <= N)
        print(data, index * 2, N, sequence);
    if (index * 2 > N)
        for (auto iter = sequence.begin(); iter != sequence.end(); iter++)
            std::cout << *iter << (iter != sequence.end() - 1 ? " " : "\n");
}

int main()
{
    int N = 0;
    std::cin >> N;
    std::vector<int> data(N + 1);
    for (int i = 1; i <= N; i++)
        std::cin >> data[i];
    print(data, 1, N, std::vector<int>());
    bool max = false, min = false, no = false;
    data.push_back(data[N]);
    N >>= 1;
    for (int i = 1; i <= N && !no; i++)
    {
        if (data[i] >= data[i * 2] && data[i] >= data[i * 2 + 1])
            max = true;
        else if (data[i] <= data[i * 2] && data[i] <= data[i * 2 + 1])
            min = true;
        else
            no = true;
    }
    if (max && !min && !no)
        std::cout << "Max Heap" << std::endl;
    else if (!max && min && !no)
        std::cout << "Min Heap" << std::endl;
    else
        std::cout << "Not Heap" << std::endl;
    return 0;
}
