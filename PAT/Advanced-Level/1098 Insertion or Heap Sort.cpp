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

void heap_sort(vector<int> &data, int end)
{
    for (int i = (end - 1) >> 1; i >= 0; i--)
    {
        int tmp = data[i], parent = i;
        for (int child = i * 2 + 1; child <= end; parent = child, child = child * 2 + 1)
        {
            if (child + 1 <= end && data[child + 1] > data[child])
                child++;
            if (data[child] > tmp)
                data[parent] = data[child];
            else
                break;
        }
        data[parent] = tmp;
    }
}

vector<int> heap(vector<int> data, vector<int> sequence)
{
    bool found = false;
    for (int i = data.size() - 1; i >= 1; i--)
    {
        heap_sort(data, i);
        if (found)
            return data;
        if (data == sequence)
            found = true;
        std::swap(data[0], data[i]);
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
    std::cout << (result.empty() ? "Heap Sort" : "Insertion Sort") << std::endl;
    if (result.empty())
        result = heap(data, sequence);
    for (auto iter = result.begin(); iter != result.end(); iter++)
        std::cout << *iter << (iter != result.end() - 1 ? " " : "\n");
    return 0;
}
