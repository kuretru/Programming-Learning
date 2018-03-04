#include <stdio.h>
#include <string.h>
int cmp(char *x, char *y)
{
    int xl = strlen(x);
    int yl = strlen(y);
    if (xl > yl)
        return 1;
    else if (xl == yl)
        return strcmp(x, y);
    return 0;
}
int main()
{
    int count, max = 0;
    char data[20][101];
    scanf("%d\n", &count);
    for (int i = 0; i < count; i++)
        gets(data[i]);
    for (int i = 1; i < count; i++)
    {
        if (cmp(data[i], data[max]) > 0)
            max = i;
    }
    printf("%d\n", max + 1);
    puts(data[max]);
    return 0;
}
