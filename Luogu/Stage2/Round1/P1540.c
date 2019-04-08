#include <stdio.h>
int count, max, memory[101];
int contains(int key)
{
    for (int i = 0; i < count; i++)
        if (memory[i] == key)
            return i;
    return -1;
}
void clear()
{
    for (int i = 1; i < max; i++)
        memory[i - 1] = memory[i];
    count--;
}
int main()
{
    int groups, result = 0;
    scanf("%d %d", &max, &groups);
    while (groups--)
    {
        int key;
        scanf("%d", &key);
        if (contains(key) > -1)
            continue;
        if (count >= max)
            clear();
        memory[count++] = key;
        result++;
    }
    printf("%d", result);
    return 0;
}
