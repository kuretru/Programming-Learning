#include <iostream>

typedef struct
{
    int raw = 0;
    int key = 0;
    int result = 0;
} DS;

int main()
{
    DS data[2];
    std::cin >> data[0].raw >> data[0].key >> data[1].raw >> data[1].key;
    for (int i = 0; i < 2; i++)
    {
        while (data[i].raw > 0)
        {
            if (data[i].raw % 10 == data[i].key)
                data[i].result = data[i].result * 10 + data[i].key;
            data[i].raw /= 10;
        }
    }
    std::cout << data[0].result + data[1].result << std::endl;
    return 0;
}
