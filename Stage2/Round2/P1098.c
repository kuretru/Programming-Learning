#include <ctype.h>
#include <stdio.h>
#include <string.h>
int cmp(char a, char b)
{
    if (a >= '0' && a <= '9' && b >= '0' && b <= '9')
        return 1;
    if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z')
        return 1;
    return 0;
}
int main()
{
    char text[101];
    int p1, p2, p3;
    scanf("%d %d %d\n", &p1, &p2, &p3);
    gets(text);
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] != '-')
            putchar(text[i]);
        else
        {
            if (text[i - 1] >= text[i + 1] || !cmp(text[i - 1], text[i + 1]))
            {
                putchar('-');
                continue;
            }
            int count = text[i + 1] - text[i - 1] - 1;
            char symbol = p3 == 1 ? text[i - 1] : text[i + 1];
            for (int j = 1; j <= count; j++)
            {
                char c;
                if (p3 == 1)
                    c = symbol + j;
                else
                    c = symbol - j;
                if (p1 == 1)
                    c = tolower(c);
                else if (p1 == 2)
                    c = toupper(c);
                else
                    c = '*';
                for (int k = 0; k < p2; k++)
                    putchar(c);
            }
        }
    }
    return 0;
}
