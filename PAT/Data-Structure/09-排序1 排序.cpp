#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

void algorithm_sort(std::vector<int> &data); // <algorithm>库实现的排序
void bubble_sort(std::vector<int> &data);    // 冒泡排序
void insertion_sort(std::vector<int> &data); // 插入排序

typedef void (*sort_interface)(std::vector<int> &data); // 排序接口
sort_interface sort = insertion_sort;                   // 指定排序实现

int main()
{
    std::ios::sync_with_stdio(false);
    int count;
    std::cin >> count;
    std::vector<int> data(count);
    for (int i = 0; i < count; i++)
    {
        std::cin >> data[i];
        // data[i] = rand();
    }
    clock_t start = clock();
    sort(data);
    double seconds = (clock() - start) * 1.0 / CLOCKS_PER_SEC;
    // std::cout << seconds << std::endl;
    for (int i = 0; i < count; i++)
        std::cout << data[i] << (i < count - 1 ? " " : "\n");
    return 0;
}

void algorithm_sort(std::vector<int> &data)
{
    std::sort(data.begin(), data.end());
}

void bubble_sort(std::vector<int> &data)
{
    for (size_t i = data.size() - 1; i >= 0; i--)
    {
        bool complete = true;
        for (size_t j = 0; j < i; j++)
        {
            if (data[j] > data[j + 1])
            {
                std::swap(data[j], data[j + 1]);
                complete = false;
            }
        }
        if (complete)
            break;
    }
}

void insertion_sort(std::vector<int> &data)
{
    for (size_t i = 1, j; i < data.size(); i++)
    {
        int tmp = data[i];
        for (j = i; j > 0 && data[j - 1] > tmp; j--)
            data[j] = data[j - 1];
        data[j] = tmp;
    }
}
