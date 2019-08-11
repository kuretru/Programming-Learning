#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

using std::vector;

void algorithm_sort(vector<int> &data); // <algorithm>库实现的排序 36ms 68ms 801ms 9325ms
void insertion_sort(vector<int> &data); // 插入排序 3201ms
void shell_sort(vector<int> &data);     // 希尔排序 35ms 554ms 6852ms 81538ms
void bubble_sort(vector<int> &data);    // 冒泡排序 TLE*3
void quick_sort(vector<int> &data);     // 快速排序 59ms 303ms 3579ms 40963ms
void selection_sort(vector<int> &data); // 选择排序 TLE*5
void heap_sort(vector<int> &data);      // 堆排序　 46ms 473ms 7103ms 98014ms
void merge_sort(vector<int> &data);     // 归并排序 33ms 491ms 5696ms 64947ms
void radix_sort(vector<int> &data);     // 基数排序 38ms 780ms 8007ms 79211ms

int quick_sort_pivot_median3(vector<int> &data, int left, int right); // 快速排序枢轴三分取中
int quick_sort_pivot_random(vector<int> &data, int left, int right);  // 快速排序枢轴取随机数字
int quick_sort_pivot_first(vector<int> &data, int left, int right);   // 快速排序枢轴取第一个

typedef void (*sort_interface)(vector<int> &data);                                 // 排序函数接口
typedef int (*quick_sort_pivot_interface)(vector<int> &data, int left, int right); // 快速排序枢轴函数接口

// 需更改的常量
sort_interface sort = radix_sort;                                       // 指定排序函数实现
quick_sort_pivot_interface quick_sort_pivot = quick_sort_pivot_median3; // 指定快速排序枢轴函数实现，将枢轴移至第一个位置
int QUICK_SORT_THRESHOLD = 50;                                          // 快速排序转插入排序的阈值，-1为仅使用快速排序
bool DEBUG = false;                                                     // 调试开关

int main()
{

    std::ios::sync_with_stdio(false);
    int count;
    std::cin >> count;
    vector<int> data(count), standard;

    if (DEBUG)
    {
        srand(time(0));
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
    if (DEBUG)
    {
        double ms = (clock() - start) * 1.0 / CLOCKS_PER_SEC * 1000;
        std::cout << "spend " << ms << " milliseconds" << std::endl;
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

void algorithm_sort(vector<int> &data)
{
    std::sort(data.begin(), data.end());
}

void insertion_sort_core(vector<int> &data, int left, int right)
{
    for (int i = left + 1, j; i <= right; i++)
    {
        int tmp = data[i];
        for (j = i; j > left && data[j - 1] > tmp; j--)
            data[j] = data[j - 1];
        data[j] = tmp;
    }
}

void insertion_sort(vector<int> &data)
{
    insertion_sort_core(data, 0, data.size() - 1);
}

void shell_sort(vector<int> &data)
{
    int sequence = 0;
    int sedgewick[] = {67084289, 37730305, 16764929,
                       9427969, 4188161, 2354689, 1045505, 587521, 260609, 146305,
                       64769, 36289, 16001, 8929, 3905, 2161, 929, 505, 209, 109, 41, 19, 5, 1, 0};
    for (sequence = 0; sedgewick[sequence] >= (int)data.size(); sequence++)
        ;
    for (int d = sedgewick[sequence]; d > 0; d = sedgewick[++sequence])
    {
        for (int i = d, j; i < (int)data.size(); i++)
        {
            int tmp = data[i];
            for (j = i; j >= d && data[j - d] > tmp; j -= d)
                data[j] = data[j - d];
            data[j] = tmp;
        }
    }
}

void bubble_sort(vector<int> &data)
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

int quick_sort_pivot_median3(vector<int> &data, int left, int right)
{
    int mid = (left + right) >> 1;
    if (data[mid] > data[left])
        std::swap(data[mid], data[left]);
    if (data[left] > data[right])
        std::swap(data[left], data[right]);
    if (data[mid] > data[left])
        std::swap(data[mid], data[left]);
    return data[left];
}

int quick_sort_pivot_random(vector<int> &data, int left, int right)
{
    srand(time(0));
    int pivot = rand() % (right - left + 1) + left;
    std::swap(data[left], data[pivot]);
    return data[left];
}

int quick_sort_pivot_first(vector<int> &data, int left, int right)
{
    return data[left];
}

void quick_sort_core(vector<int> &data, int left, int right)
{
    if (left >= right)
        return;
    if (QUICK_SORT_THRESHOLD != -1 && right - left < QUICK_SORT_THRESHOLD)
        insertion_sort_core(data, left, right);
    int pivot = quick_sort_pivot(data, left, right);
    int low = left, high = right;
    while (low < high)
    {
        while (low < high && pivot <= data[high])
            high--;
        data[low] = data[high];
        while (low < high && pivot >= data[low])
            low++;
        data[high] = data[low];
    }
    data[low] = pivot;
    quick_sort_core(data, left, low - 1);
    quick_sort_core(data, low + 1, right);
}

void quick_sort(vector<int> &data)
{
    quick_sort_core(data, 0, data.size() - 1);
}

void selection_sort(vector<int> &data)
{
    for (auto iter = data.begin(); iter != data.end(); iter++)
    {
        auto min = std::min_element(iter, data.end());
        if (iter != min)
            std::swap(*iter, *min);
    }
}

void heap_sort_adjust(vector<int> &data, int key, int length)
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

void heap_sort(vector<int> &data)
{
    for (int i = (data.size() - 1) >> 1; i >= 0; i--)
        heap_sort_adjust(data, i, data.size());
    for (int i = data.size() - 1; i > 0; i--)
    {
        std::swap(data[0], data[i]);
        heap_sort_adjust(data, 0, i);
    }
}

void merge_sort_merge(vector<int> &data, vector<int> &tmp, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = i;
    for (; i <= mid && j <= high; k++)
    {
        if (data[i] < data[j])
            tmp[k] = data[i++];
        else
            tmp[k] = data[j++];
    }
    while (i <= mid)
        tmp[k++] = data[i++];
    while (j <= high)
        tmp[k++] = data[j++];
    for (i = low; i <= high; i++)
        data[i] = tmp[i];
}

void merge_sort_core(vector<int> &data, vector<int> &tmp, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) >> 1;
    merge_sort_core(data, tmp, left, mid);
    merge_sort_core(data, tmp, mid + 1, right);
    merge_sort_merge(data, tmp, left, mid, right);
}

void merge_sort(vector<int> &data)
{
    vector<int> tmp(data.size());
    merge_sort_core(data, tmp, 0, data.size() - 1);
}

void radix_sort_merge(vector<int> &data, vector<vector<int>> &buckets, int &index, int start, int end)
{
    for (int i = start; i < end; i++)
        for (auto iter = buckets[i].begin(); iter != buckets[i].end(); iter++)
            data[index++] = *iter;
}

void radix_sort(vector<int> &data)
{
    vector<vector<int>> buckets(16);
    for (unsigned int times = 0, hex = 0xf; times <= 28; times += 4, hex <<= 4)
    {
        for (auto iter = buckets.begin(); iter != buckets.end(); iter++)
            iter->clear();
        for (auto iter = data.begin(); iter != data.end(); iter++)
            buckets[(*iter & hex) >> times].push_back(*iter);
        int index = 0;
        if (times == 28)
        {
            radix_sort_merge(data, buckets, index, 8, 16);
            radix_sort_merge(data, buckets, index, 0, 8);
        }
        else
            radix_sort_merge(data, buckets, index, 0, 16);
    }
}
