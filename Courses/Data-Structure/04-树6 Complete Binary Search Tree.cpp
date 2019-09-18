#include <algorithm>
#include <iostream>
#include <vector>

int MAX_COUNT[] = {1, 3, 7, 15, 31, 63, 127, 255, 511, 1023};

void preOrder(std::vector<int> &data, int left, int right, std::vector<int> &result, int index)
{
    if (left > right)
        return;
    int count = right - left + 1;
    int treeCount = 0;
    for (int i = 9; i >= 0 && MAX_COUNT[i] >= count; i--)
        treeCount = MAX_COUNT[i];

    int diff = treeCount - count;
    int lastHalfLevelCount = ((treeCount >> 1) + 1) >> 1;
    int leftCount = (treeCount - 1) >> 1;
    if (diff > lastHalfLevelCount)
        leftCount -= diff - lastHalfLevelCount;
    int mid = left + leftCount;

    result[index] = data[mid];
    preOrder(data, left, mid - 1, result, index << 1);
    preOrder(data, mid + 1, right, result, (index << 1) + 1);
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> data(N + 1), result(N + 1);
    for (int i = 1; i <= N; i++)
        std::cin >> data[i];
    std::sort(data.begin(), data.end());
    preOrder(data, 1, N, result, 1);
    for (int i = 1; i <= N; i++)
        std::cout << result[i] << (i != N ? " " : "\n");
    return 0;
}
