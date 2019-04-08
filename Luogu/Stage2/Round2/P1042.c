#include <stdio.h>
#include <stdlib.h>
int main()
{
    int count = 0, score21[2977][2] = {0};
    int win = 0, lose = 0;
    while (1)
    {
        char c = getchar();
        if (c == 'E')
        {
            printf("%d:%d\n\n", win, lose);
            count++;
            break;
        }
        if (c == 'W')
        {
            win++;
            score21[count][0]++;
        }
        else if (c == 'L')
        {
            lose++;
            score21[count][1]++;
        }
        if ((win >= 11 || lose >= 11) && abs(win - lose) >= 2)
        {
            printf("%d:%d\n", win, lose);
            win = 0;
            lose = 0;
        }
        if ((score21[count][0] >= 21 || score21[count][1] >= 21) &&
            abs(score21[count][0] - score21[count][1]) >= 2)
            count++;
    }
    for (int i = 0; i < count; i++)
        printf("%d:%d\n", score21[i][0], score21[i][1]);
    return 0;
}
