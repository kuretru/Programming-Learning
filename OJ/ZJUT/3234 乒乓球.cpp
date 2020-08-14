#include <cstdio>
#include <string>

void compute(std::string match, int rule)
{
    int step = 0, left = 0, right = 0;
    while (step < match.length())
    {
        if (match[step++] == 'W')
            left++;
        else
            right++;
        if ((left >= rule || right >= rule) && abs(left - right) >= 2)
        {
            printf("%d:%d\n", left, right);
            left = right = 0;
        }
    }
    printf("%d:%d\n", left, right);
}

int main()
{
    std::string match = "";
    char c = ' ';
    while ((c = getchar()) != EOF)
    {
        if (c == 'E')
            break;
        if (c != 'W' && c != 'L')
            continue;
        match += c;
    }
    compute(match, 11);
    puts("");
    compute(match, 21);
    return 0;
}
