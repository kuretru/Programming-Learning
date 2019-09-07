#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using std::map;
using std::set;
using std::vector;

void buildTree(vector<int> &post, vector<int> &in, map<int, int> &tree, set<int> &nodes, int postEnd, int inStart, int inEnd, int index)
{
    if (inStart > inEnd)
        return;
    int value = post[postEnd];
    tree[value] = index;
    nodes.insert(index);
    int indexOfValue = std::distance(in.begin(), std::find(in.begin(), in.end(), post[postEnd]));
    buildTree(post, in, tree, nodes, postEnd - 1 - (inEnd - indexOfValue), inStart, indexOfValue - 1, index * 2);
    buildTree(post, in, tree, nodes, postEnd - 1, indexOfValue + 1, inEnd, index * 2 + 1);
}

void byPass(int count)
{
    std::string key = "";
    while (count--)
        std::cin >> key;
}

int main()
{
    int N = 0, M = 0;
    std::cin >> N;
    vector<int> post(N), in(N);
    map<int, int> tree;
    set<int> nodes;
    for (int i = 0; i < N; i++)
        std::cin >> post[i];
    for (int i = 0; i < N; i++)
        std::cin >> in[i];
    buildTree(post, in, tree, nodes, N - 1, 0, N - 1, 1);
    std::cin >> M;
    while (M--)
    {
        bool result = true;
        std::string command = "";
        std::cin >> command;
        if (command == "It")
        {
            std::cin >> command >> command >> command >> command;
            for (auto iter = nodes.begin(); iter != nodes.end(); iter++)
            {
                if (nodes.count(*iter * 2) ^ nodes.count(*iter * 2 + 1)) // 异或，为真说明有且仅有一个儿子
                {
                    result = false;
                    break;
                }
            }
        }
        else
        {
            int first = std::stoi(command), second = 0;
            std::cin >> command;
            if (command == "and")
            {
                std::cin >> second >> command >> command;
                int x = tree[first], y = tree[second];
                if (command == "on")
                {
                    std::cin >> command >> command >> command;
                    for (unsigned int i = 0x8ffffff; i >= 1; i >>= 1)
                    {
                        if ((x >= i && y < i) || (y >= i && x < i))
                        {
                            result = false;
                            break;
                        }
                    }
                }
                else if ((x % 2 == 1 && y != x - 1) || (y % 2 == 1 && x != y - 1))
                    result = false;
            }
            else
            {
                std::cin >> command >> command;
                if (command == "root")
                    result = tree[first] == 1;
                else if (command == "parent")
                {
                    std::cin >> command >> second;
                    result = tree[second] >> 1 == tree[first];
                }
                else if (command == "left")
                {
                    std::cin >> command >> command >> second;
                    result = tree[first] == tree[second] * 2;
                }
                else if (command == "right")
                {
                    std::cin >> command >> command >> second;
                    result = tree[first] == tree[second] * 2 + 1;
                }
            }
        }
        std::cout << (result ? "Yes" : "No") << std::endl;
    }
    return 0;
}
