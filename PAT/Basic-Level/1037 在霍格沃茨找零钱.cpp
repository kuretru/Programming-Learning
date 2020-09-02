#include <iostream>

struct money
{
    int galleon = 0;
    int sickle = 0;
    int knut = 0;
    long sum;
};

int main()
{
    money data[2];
    for (int i = 0; i < 2; i++)
    {
        scanf("%d.%d.%d", &data[i].galleon, &data[i].sickle, &data[i].knut);
        data[i].sum = data[i].sickle + data[i].galleon * 17;
        data[i].sum = data[i].knut + data[i].sum * 29;
    }
    data[1].sum -= data[0].sum;
    data[1].knut = data[1].sum % 29;
    data[1].sickle = data[1].sum / 29;
    data[1].galleon = data[1].sickle / 17;
    data[1].sickle %= 17;
    if (data[1].sum >= 0)
        printf("%d.%d.%d\n", data[1].galleon, data[1].sickle, data[1].knut);
    else
        printf("%d.%d.%d\n", data[1].galleon, -data[1].sickle, -data[1].knut);
    return 0;
}
