#include <iostream>
#include <map>
#include <string>
#include <vector>

struct node
{
    char character = '#';
    int frequency = 0;
    node *left = NULL;
    node *right = NULL;
};

int getWPL();
void buildTree(node *head, char character, std::string code);
int verifyWPL(node *head, int level);

std::map<char, node *> data;

int main()
{
    int N, M;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        node *n = new node();
        std::cin >> n->character >> n->frequency;
        data[n->character] = n;
    }
    int wpl = getWPL();
    std::cin >> M;
    while (M--)
    {
        node *head = new node();
        for (int i = 0; i < N; i++)
        {
            char character;
            std::string code;
            std::cin >> character >> code;
            buildTree(head, character, code);
        }
        int studentWpl = verifyWPL(head, 0);
        std::cout << (studentWpl == wpl ? "Yes" : "No") << std::endl;
    }
    return 0;
}

int computerWPL(node *head, int level)
{
    if (!head)
        return 0;
    if (!head->left && !head->right)
        return head->frequency * level;
    return computerWPL(head->left, level + 1) + computerWPL(head->right, level + 1);
}

int getWPL()
{
    std::multimap<int, node *> map;
    for (auto iter = data.begin(); iter != data.end(); iter++)
        map.insert(std::pair<int, node *>(iter->second->frequency, iter->second));
    while (map.size() > 1)
    {
        node *first = map.begin()->second;
        map.erase(map.begin());
        node *second = map.begin()->second;
        map.erase(map.begin());
        node *parent = new node();
        parent->frequency = first->frequency + second->frequency;
        parent->left = first;
        parent->right = second;
        map.insert(std::pair<int, node *>(parent->frequency, parent));
    }
    node *head = map.begin()->second;
    return computerWPL(head, 0);
}

void buildTree(node *head, char character, std::string code)
{
    for (int i = 0; i < code.size(); i++)
    {
        if (code[i] == '0')
        {
            if (!head->left)
                head->left = new node();
            head = head->left;
        }
        else
        {
            if (!head->right)
                head->right = new node();
            head = head->right;
        }
    }
    if (head->character != '#')
        head->frequency = -1;
    head->character = character;
}

int verifyWPL(node *head, int level)
{
    if (!head)
        return 0;
    if (head->frequency < 0)
        return -1;
    if (head->character == '#')
    {
        int left = verifyWPL(head->left, level + 1);
        int right = verifyWPL(head->right, level + 1);
        if (left == -1 || right == -1)
            return -1;
        return left + right;
    }
    if (head->left || head->right)
        return -1;
    return level * data[head->character]->frequency;
}
