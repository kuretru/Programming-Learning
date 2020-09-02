#include <cctype>
#include <iostream>
#include <string>

const std::string DAY[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
    int day = -1, hour = 0, minute = 0;
    std::string a = "", b = "";
    std::cin >> a >> b;
    for (int i = 0; i < a.length() && i < b.length(); i++)
    {
        if (a[i] == b[i])
        {
            if (day == -1 && 'A' <= a[i] && a[i] <= 'G')
                day = a[i] - 'A';
            else if (day != -1 && (('A' <= a[i] && a[i] <= 'N') || isdigit(a[i])))
            {
                if ('0' <= a[i] && a[i] <= '9')
                    hour = a[i] - '0';
                else
                    hour = a[i] - 'A' + 10;
                break;
            }
        }
    }
    std::cin >> a >> b;
    for (int i = 0; i < a.length() && i < b.length(); i++)
    {
        if (a[i] == b[i] && isalpha(a[i]))
        {
            minute = i;
            break;
        }
    }
    printf("%s %02d:%02d\n", DAY[day].data(), hour, minute);
    return 0;
}
