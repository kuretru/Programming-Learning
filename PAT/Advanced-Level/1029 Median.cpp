#include <iostream>
#include <vector>

std::vector<int> input()
{
    int count = 0;
    std::cin >> count;
    std::vector<int> result(count);
    for (int i = 0; i < count; i++)
        std::cin >> result[i];
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::vector<int> S1 = input();
    std::vector<int> S2 = input();
    std::vector<int> data(S1.size() + S2.size());
    int mid = (data.size() + 1) / 2 - 1;
    int i = 0, j = 0, k = 0;
    while (i < S1.size() && j < S2.size() && k <= mid)
    {
        if (S1[i] <= S2[j])
            data[k++] = S1[i++];
        else
            data[k++] = S2[j++];
    }
    while (i < S1.size() && k <= mid)
        data[k++] = S1[i++];
    while (j < S2.size() && k <= mid)
        data[k++] = S2[j++];
    std::cout << data[mid] << std::endl;
    return 0;
}
