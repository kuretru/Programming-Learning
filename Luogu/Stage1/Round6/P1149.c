#include <stdio.h>
int data[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int count(int number)
{
    int count = 0;
    while (1)
    {
        count += data[number % 10];
        number /= 10;
        if (number == 0)
            break;
    }
    return count;
}
int main()
{
    int matches, result = 0;
    scanf("%d", &matches);
    matches -= 4;
    for (int i = 0; i <= 1111; i++)
    {
        for (int j = i; j <= 1111; j++)
        {
            if (count(i) + count(j) + count(i + j) == matches)
            {
                if (i != j)
                    result += 2;
                else
                    result++;
            }
        }
    }
    printf("%d", result);
    return 0;
}
