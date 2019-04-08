#include <ctype.h>
#include <stdio.h>
#include <string.h>
char word[12], text[1000002], tmp[1000002];
int wLen, tLen;
void getWord()
{
    int i = 0;
    char c;
    scanf("%c", &c);
    while (i < 11)
    {
        c = tolower(c);
        if (c >= 'a' && c <= 'z')
            word[i++] = c;
        else if (c == '\n')
        {
            word[i++] = '\0';
            break;
        }
        scanf("%c", &c);
    }
    wLen = strlen(word);
}
void getText()
{
    int i;
    text[0] = ' ';
    text[1] = '\0';
    gets(tmp);
    strcat(tmp, " ");
    strcat(text, tmp);
    tLen = strlen(text);
    for (i = 1; i < tLen; i++)
        text[i] = tolower(text[i]);
}
int main()
{
    int i, j;
    int count = 0, first = -1;
    getWord();
    getText();
    for (i = 1; i < tLen - wLen; i++)
    {
        if (text[i - 1] == ' ' && text[i + wLen] == ' ')
        {
            for (j = 0; j < wLen; j++)
            {
                if (word[j] != text[i + j])
                    break;
                if (j == wLen - 1)
                {
                    if (first == -1)
                        first = i - 1;
                    count++;
                }
            }
        }
    }
    if (count > 0)
        printf("%d ", count);
    printf("%d", first);
    return 0;
}
