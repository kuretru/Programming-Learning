#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

const int TABLE[] = {1, 3, 7, 15, 31, 63, 127, 255, 511, 1023};

void buildTree(vector<int> &data, vector<int> &result, int start, int end, int index)
{
    if (start > end)
        return;
    int count = end - start + 1;
    int maxCount = 0;
    for (int i = 0; maxCount < count; i++)
        maxCount = TABLE[i];
    int lessCount = maxCount - count;
    int lastCount = (maxCount >> 1) + 1;
    int lastLeftCount = std::min(lastCount - lessCount, lastCount >> 1);
    int leftCount = ((lastCount - 1) >> 1) + lastLeftCount;
    result[index] = data[start + leftCount];
    buildTree(data, result, start, start + leftCount - 1, index * 2 + 1);
    buildTree(data, result, start + leftCount + 1, end, index * 2 + 2);
}

int main()
{
    int N = 0;
    std::cin >> N;
    vector<int> data(N), result(N);
    for (int i = 0; i < N; i++)
        std::cin >> data[i];
    std::sort(data.begin(), data.end());
    buildTree(data, result, 0, N - 1, 0);
    for (int i = 0; i < N; i++)
        std::cout << result[i] << (i < N - 1 ? " " : "\n");
    return 0;
}
