#include <iostream>
#include <vector>
std::vector<int> data;
int M, N;
bool max, min;
void heap(int index)
{
    if (index > N)
        return;
    bool maxFlag = false, minFlag = false;
    if (index * 2 <= N && data[index] >= data[index * 2])
        maxFlag = true;
    if (index * 2 + 1 <= N && data[index] >= data[index * 2 + 1])
        maxFlag &= true;
    if (index * 2 <= N && data[index] <= data[index * 2])
        minFlag = true;
    if (index * 2 + 1 <= N && data[index] <= data[index * 2 + 1])
        minFlag &= true;
    if (maxFlag)
        max = true;
    if (minFlag)
        min = true;
    heap(index * 2);
    heap(index * 2 + 1);
}
void postOrder(int index)
{
    if (index > N)
        return;
    postOrder(index * 2);
    postOrder(index * 2 + 1);
    std::cout << data[index] << (index == 1 ? "\n" : " ");
}
int main()
{
    std::cin >> M >> N;
    while (M--)
    {
        min = max = false;
        data.resize(N + 1);
        for (int i = 1; i <= N; i++)
            std::cin >> data[i];
        heap(1);
        if (max && !min)
            std::cout << "Max Heap" << std::endl;
        else if (!max && min)
            std::cout << "Min Heap" << std::endl;
        else
            std::cout << "Not Heap" << std::endl;
        postOrder(1);
    }
    return 0;
}
