#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int key;
} Record;
int compare(Record *data, int x, int y)
{
    return data[x].key > data[y].key;
}
void swap(Record *data, int x, int y)
{
    Record tmp = data[x];
    data[x] = data[y];
    data[y] = tmp;
}
void median(Record *data, int x, int y, int z)
{
    if (compare(data, y, x))
        swap(data, y, x);
    if (compare(data, x, z))
        swap(data, x, z);
    if (compare(data, y, x))
        swap(data, y, x);
}
int orderly(Record *data, int low, int high)
{
    for (int i = low; i < high; i++)
        if (compare(data, i, i + 1))
            return 0;
    return 1;
}
void quick_sort(Record *data, int low, int high)
{
    if (low >= high)
        return;
    int i = low;
    int j = high;
    median(data, low, (low + high) / 2, high);
    data[0] = data[low];
    while (i < j)
    {
        while (i < j && !compare(data, 0, j))
            j--;
        data[i] = data[j];
        while (i < j && !compare(data, i, 0))
            i++;
        data[j] = data[i];
    }
    data[i] = data[0];
    if (!orderly(data, low, i - 1))
        quick_sort(data, low, i - 1);
    if (!orderly(data, i + 1, high))
        quick_sort(data, i + 1, high);
}
int main()
{
    int count;
    Record *data;
    scanf("%d", &count);
    data = (Record *)malloc((count + 1) * sizeof(Record));
    for (int i = 1; i <= count; i++)
        scanf("%d", &data[i].key);
    quick_sort(data, 1, count);
    for (int i = 1; i <= count; i++)
        printf("%d%c", data[i].key, i < count ? ' ' : '\n');
    free(data);
    return 0;
}
