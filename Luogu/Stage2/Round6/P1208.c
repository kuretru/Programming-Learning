#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int value;
    int count;
} farmer;
int qcmp(const void *a, const void *b)
{
    farmer *x = (farmer *)a;
    farmer *y = (farmer *)b;
    return x->value - y->value;
}
int main()
{
    int n, m, cost = 0, bought = 0;
    farmer *data;
    scanf("%d %d", &n, &m);
    data = (farmer *)malloc(m * sizeof(farmer));
    for (int i = 0; i < m; i++)
        scanf("%d %d", &data[i].value, &data[i].count);
    qsort(data, m, sizeof(farmer), qcmp);
    for (int i = 0; i < m; i++)
    {
        int quantity = data[i].count;
        if (data[i].count + bought > n)
            quantity = n - bought;
        cost += data[i].value * quantity;
        bought += quantity;
        if (bought >= n)
            break;
    }
    printf("%d", cost);
    free(data);
    return 0;
}
