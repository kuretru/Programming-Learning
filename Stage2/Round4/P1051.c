#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
struct student
{
    char name[21];
    int sum;
};
int main()
{
    struct student list[100];
    int count, total = 0;
    scanf("%d\n", &count);
    for (int i = 0; i < count; i++)
    {
        int pj, py, lw;
        char gb, xb;
        scanf("%s %d %d %c %c %d", list[i].name, &pj, &py, &gb, &xb, &lw);
        gb = toupper(gb);
        xb = toupper(xb);
        list[i].sum = 0;
        if (pj > 80 && lw > 0)
            list[i].sum += 8000;
        if (pj > 85 && py > 80)
            list[i].sum += 4000;
        if (pj > 90)
            list[i].sum += 2000;
        if (pj > 85 && xb == 'Y')
            list[i].sum += 1000;
        if (py > 80 && gb == 'Y')
            list[i].sum += 850;
        total += list[i].sum;
    }
    int max = 0;
    for (int i = 1; i < count; i++)
        if (list[i].sum > list[max].sum)
            max = i;
    printf("%s\n%d\n%d", list[max].name, list[max].sum, total);
    return 0;
}
