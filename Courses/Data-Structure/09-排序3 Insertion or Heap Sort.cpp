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

void heap_sort_adjust(std::vector<int> &data, int key, int length)
{
    int value = data[key], parent, child;
    for (parent = key, child = (parent << 1) + 1; child < length; child = (parent << 1) + 1)
    {
        if ((child + 1) < length && data[child + 1] > data[child])
            child++;
        if (value > data[child])
            break;
        data[parent] = data[child];
        parent = child;
    }
    data[parent] = value;
}

std::vector<int> heap_sort(std::vector<int> data, std::vector<int> sequence)
{
    bool found = false;
    for (int i = (data.size() - 1) >> 1; i >= 0; i--)
        heap_sort_adjust(data, i, data.size());
    for (int i = data.size() - 1; i > 0; i--)
    {
        std::swap(data[0], data[i]);
        heap_sort_adjust(data, 0, i);
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
    std::cout << (result.size() != 0 ? "Insertion Sort" : "Heap Sort") << std::endl;
    if (result.size() == 0)
        result = heap_sort(data, sequence);
    for (auto iter = result.begin(); iter != result.end(); iter++)
        std::cout << *iter << (iter != result.end() - 1 ? " " : "\n");
    return 0;
}
