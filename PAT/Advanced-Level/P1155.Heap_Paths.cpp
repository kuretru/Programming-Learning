#include <iostream>
#include <vector>
std::vector<int> data;
int count;
bool max = false;
bool min = false;
void heap(int index, std::vector<int> path)
{
    if (index > count)
        return;
    path.push_back(data[index]);
    if (index * 2 > count)
    {
        for (auto iter = path.begin(); iter != path.end(); iter++)
        {
            std::cout << *iter << (iter != path.end() - 1 ? " " : "\n");
        }
    }
    else
    {
        heap(index * 2 + 1, path);
        heap(index * 2, path);
        bool maxFlag = false, minFlag = false;
        if (data[index] >= data[index * 2])
            maxFlag = true;
        else if (data[index] <= data[index * 2])
            minFlag = true;
        if (index * 2 + 1 <= count && data[index] >= data[index * 2 + 1])
            maxFlag = maxFlag & true;
        else if (index * 2 + 1 <= count && data[index] <= data[index * 2 + 1])
            minFlag = minFlag & true;
        if (maxFlag)
            max = true;
        if (minFlag)
            min = true;
    }
    path.pop_back();
}
int main()
{
    std::cin >> count;
    data.resize(count + 1);
    for (int i = 1; i <= count; i++)
    {
        std::cin >> data[i];
    }
    heap(1, std::vector<int>());
    if (max && !min)
        std::cout << "Max Heap" << std::endl;
    else if (!max && min)
        std::cout << "Min Heap" << std::endl;
    else
        std::cout << "Not Heap" << std::endl;
    return 0;
}
