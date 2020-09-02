#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> data;
    int count = 0;
    std::cin >> count;
    while (count--)
    {
        std::string a, b;
        std::cin >> a >> b;
        data[a + b]++;
    }
    int a = data["CJ"] + data["JB"] + data["BC"];
    int b = data["CC"] + data["JJ"] + data["BB"];
    int c = data["JC"] + data["BJ"] + data["CB"];
    printf("%d %d %d\n", a, b, c);
    printf("%d %d %d\n", c, b, a);
    std::cout << (data["BC"] >= data["CJ"] && data["BC"] >= data["JB"] ? "B" : (data["CJ"] >= data["JB"] ? "C" : "J")) << " " << (data["CB"] >= data["JC"] && data["CB"] >= data["BJ"] ? "B" : (data["JC"] >= data["BJ"] ? "C" : "J"));
    return 0;
}
