#include <stdio.h>
#include <string.h>
int main()
{
    int data[26] = {0};
    char text[101];
    for (int i = 0; i < 4; i++)
    {
        gets(text);
        for (int j = 0; j < 100; j++)
        {
            if (text[j] == '\0')
                break;
            else if (text[j] >= 'A' && text[j] <= 'Z')
                data[text[j] - 'A']++;
        }
    }
    int max = data[0];
    for (int i = 1; i < 26; i++)
        if (data[i] > max)
            max = data[i];
    for (int i = max - 1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            printf("%c%c", data[j] > i ? '*' : ' ',
                   j != 25 ? ' ' : '\n');
        }
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%c%c", 'A' + i, i != 25 ? ' ' : '\n');
    }
    return 0;
}
