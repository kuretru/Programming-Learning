#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    char pwd[51];
    scanf("%d\n", &n);
    gets(pwd);
    int length = strlen(pwd);
    for (int i = 0; i < length; i++)
        putchar((pwd[i] - 'a' + n) % 26 + 'a');
    return 0;
}
