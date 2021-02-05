#include <cstdio>
#include <stack>
#include <vector>

using std::vector;

int main()
{
    char command[11] = {0};
    std::stack<int> stack;
    vector<int> count1(1000);
    vector<vector<int>> count2(1000, vector<int>(100));
    int N = 0, number = 0;
    scanf("%d\n", &N);
    while (N--)
    {
        scanf("%s", command);
        if (command[1] == 'u')
        {
            // Push
            scanf("%d", &number);
            stack.push(number);
            int index = number / 100;
            count1[index]++;
            count2[index][number % 100]++;
        }
        else if (stack.empty())
            puts("Invalid");
        else if (command[1] == 'o')
        {
            // Pop
            number = stack.top();
            stack.pop();
            int index = number / 100;
            count1[index]--;
            count2[index][number % 100]--;
            printf("%d\n", number);
        }
        else
        {
            // PeekMedian
            int median = (stack.size() + 1) >> 1;
            int i = 0, j = 0, count = 0;
            while (count + count1[i] < median)
                count += count1[i++];
            while (count + count2[i][j] < median)
                count += count2[i][j++];
            printf("%d\n", i * 100 + j);
        }
    }
    return 0;
}
