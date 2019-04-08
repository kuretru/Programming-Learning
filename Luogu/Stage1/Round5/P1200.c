#include <stdio.h>
#include <string.h>
int calc(char text[])
{
    int length = strlen(text);
    int weight = 1;
    for (int i = 0; i < length; i++)
    {
        weight *= text[i] - 'A' + 1;
    }
    return weight % 47;
}
int main()
{
    char A[7], B[7];
    gets(A);
    gets(B);
    if (calc(A) == calc(B))
        printf("GO");
    else
        printf("STAY");
    return 0;
}
