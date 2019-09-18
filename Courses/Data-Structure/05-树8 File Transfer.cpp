#include <iostream>
#include <vector>

// 路径压缩
int find(std::vector<int> &data, int key)
{
    if (data[key] < 0)
        return key;
    // 以下三行可以这样简化：return data[key] = find(data, data[key]);
    int result = find(data, data[key]);
    data[key] = result;
    return result;
}

// 按秩归并：比较规模
void unionn(std::vector<int> &data, int root1, int root2)
{
    if (data[root1] < data[root2])
    {
        data[root1] += data[root2];
        data[root2] = root1;
    }
    else
    {
        data[root2] += data[root1];
        data[root1] = root2;
    }
}

int main()
{
    char command;
    int N, c1, c2, count = 0;
    std::cin >> N;
    std::vector<int> data(N + 1, -1);
    do
    {
        std::cin >> command;
        if (command == 'S')
            break;
        std::cin >> c1 >> c2;
        int root1 = find(data, c1);
        int root2 = find(data, c2);
        if (command == 'I')
        {
            if (root1 != root2)
                unionn(data, root1, root2);
        }
        else
            std::cout << (root1 == root2 ? "yes" : "no") << std::endl;
    } while (command != 'S');
    for (int i = 1; i <= data.size(); i++)
        if (data[i] < 0)
            count++;
    if (count == 1)
        std::cout << "The network is connected." << std::endl;
    else
        std::cout << "There are " << count << " components." << std::endl;
    return 0;
}
