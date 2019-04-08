#include <stdio.h>
#include <string.h>
char text[30];
void reverse(int low, int height)
{
    for (int i = low, j = height - 1; i < j; i++, j--)
    {
        char tmp = text[i];
        text[i] = text[j];
        text[j] = tmp;
    }
    int zero = 0;
    for (int i = low; i < height; i++)
    {
        if (text[i] == '0' && !zero)
            continue;
        else if (text[i] != '0' && !zero)
            zero = 1;
        if (text[i] != '\0')
            putchar(text[i]);
    }
    if (zero == 0)
        putchar('0');
}
int main()
{
    gets(text);
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.')
        {
            reverse(0, i);
            putchar('.');
            int zero = 0;
            for (int j = i + 1; j < length; j++)
            {
                if (text[j] == '0' && !zero)
                    text[j] = '\0';
                else if (!zero)
                    zero = 1;
            }
            if (zero == 0)
                text[i + 1] = '0';
            reverse(i + 1, length);
            break;
        }
        else if (text[i] == '/')
        {
            reverse(0, i);
            putchar('/');
            reverse(i + 1, length);
            break;
        }
        else if (text[i] == '%')
        {
            reverse(0, i);
            putchar('%');
            break;
        }
        else if (i == length - 1)
            reverse(0, length);
    }
    return 0;
}
