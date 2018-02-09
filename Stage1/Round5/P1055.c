#include <stdio.h>
#include <string.h>
int main()
{
    char c, data[15];
    gets(data);
    int result = 0, step = 1;
    for (int i = 0; i < 11; i++, step++)
    {
        if (i == 1 || i == 5)
            i++;
        result += (data[i] - '0') * step;
    }
    result = result % 11;
    if (result < 10)
        c = result + '0';
    else
        c = 'X';
    if (c == data[12])
        printf("Right\n");
    else
    {
        data[12] = c;
        puts(data);
    }
    return 0;
}
