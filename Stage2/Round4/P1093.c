#include <stdio.h>
#include <stdlib.h>
struct student
{
    int number;
    int chinese;
    int math;
    int english;
    int sum;
} list[300];
int qcmp(const void *a, const void *b)
{
    struct student *x = (struct student *)a;
    struct student *y = (struct student *)b;
    if (x->sum == y->sum)
    {
        if (x->chinese == y->chinese)
            return x->number - y->number;
        return y->chinese - x->chinese;
    }
    return y->sum - x->sum;
}
int main()
{
    int count;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        scanf("%d %d %d", &list[i].chinese, &list[i].math, &list[i].english);
        list[i].number = i + 1;
        list[i].sum = list[i].chinese + list[i].math + list[i].english;
    }
    qsort(list, count, sizeof(struct student), qcmp);
    for (int i = 0; i < 5; i++)
        printf("%d %d\n", list[i].number, list[i].sum);
    return 0;
}
