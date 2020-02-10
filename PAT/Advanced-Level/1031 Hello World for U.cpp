#include <iostream>
#include <string>

int main()
{
    std::string text = "", space = "";
    std::cin >> text;
    int N = text.length() + 2;
    int n1 = N / 3, n2 = N / 3 + N % 3;
    for (int i = 2; i < n2; i++)
        space += " ";
    for (int i = 1, j = 0, k = text.length() - 1; i < n1; i++, j++, k--)
        std::cout << text[j] << space << text[k] << std::endl;
    for (int i = n1 - 1; i < n1 + n2 - 1;i++)
        std::cout << text[i];
    std::cout << std::endl;
    return 0;
}
