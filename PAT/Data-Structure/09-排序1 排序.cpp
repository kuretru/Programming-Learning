#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

void algorithm_sort(std::vector<int> &data); // <algorithm>库实现的排序
void bubble_sort(std::vector<int> &data);    // 冒泡排序
void insertion_sort(std::vector<int> &data); // 插入排序
void shell_sort(std::vector<int> &data);     // 希尔排序

typedef void (*sort_interface)(std::vector<int> &data); // 排序接口
sort_interface sort = shell_sort;                       // 指定排序实现
bool debug = true;                                     // 调试开关

int main()
{
    std::ios::sync_with_stdio(false);
    int count;
    std::cin >> count;
    std::vector<int> data(count), standard;

    if (debug)
    {
        for (int i = 0; i < count; i++)
            data[i] = rand();
        standard = data;
        algorithm_sort(standard);
    }
    else
    {
        for (int i = 0; i < count; i++)
            std::cin >> data[i];
    }

    clock_t start = clock();
    sort(data);
    if (debug)
    {
        double seconds = (clock() - start) * 1.0 / CLOCKS_PER_SEC;
        std::cout << "spend " << seconds << " seconds" << std::endl;
        int errors = 0;
        for (int i = 0; i < count; i++)
            if (data[i] != standard[i])
                errors++;
        if (!errors)
            std::cout << "check success" << std::endl;
        else
            std::cout << "check failure " << errors << " errors" << std::endl;
    }
    else
    {
        for (int i = 0; i < count; i++)
            std::cout << data[i] << (i < count - 1 ? " " : "\n");
    }
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

void shell_sort(std::vector<int> &data)
{
    size_t sequence;
    int sedgewick[] = {64769, 36289, 16001, 8929, 3905, 2161, 929, 505, 209, 109, 41, 19, 5, 1, 0};
    for (sequence = 0; sedgewick[sequence] >= data.size(); sequence++)
        ;
    for (int d = sedgewick[sequence]; d > 0; d = sedgewick[++sequence])
    {
        for (size_t i = d, j; i < data.size(); i++)
        {
            int tmp = data[i];
            for (j = i; j >= d && data[j - d] > tmp; j -= d)
                data[j] = data[j - d];
            data[j] = tmp;
        }
    }
}
