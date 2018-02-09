#include <stdio.h>
int main()
{
    int plan[13], remain = 0, mom = 0, insufficient = 0;
    for (int i = 1; i < 13; i++)
        scanf("%d", &plan[i]);
    for (int i = 1; i < 13; i++)
    {
        remain += 300;
        remain -= plan[i];
        if (remain < 0 && insufficient == 0)
        {
            remain = 0;
            insufficient = -i;
        }
        while (remain >= 100)
        {
            remain -= 100;
            mom += 100;
        }
    }
    if (insufficient < 0)
        printf("%d", insufficient);
    else
        printf("%.0f", mom * 1.2 + remain);
    return 0;
}
