#include <stdio.h>
struct toy
{
    int direction;
    char name[10];
} list[100000];
int main()
{
    int tCount, cCount, index = 0;
    int a, s;
    scanf("%d %d", &tCount, &cCount);
    for (int i = 0; i < tCount; i++)
        scanf("%d %s", &list[i].direction, list[i].name);
    for (int i = 0; i < cCount; i++)
    {
        scanf("%d %d", &a, &s);
        s %= tCount;
        if (list[index].direction != a)
        {
            index += s;
            if (index >= tCount)
                index -= tCount;
        }
        else
        {
            index -= s;
            if (index < 0)
                index += tCount;
        }
    }
    printf("%s", list[index].name);
    return 0;
}
