#include <iostream>
#include <string>
#include <vector>

struct student
{
    std::string name = "";
    int avg_score = 0;
    int class_score = 0;
    bool xsgb = false;
    bool xbsf = false;
    int paper_count = 0;
    int scholarship = 0;
};

int main()
{
    int N = 0;
    std::cin >> N;
    std::vector<student> data(N);
    for (int i = 0; i < N; i++)
    {
        std::string xsgb, xbsf;
        std::cin >> data[i].name;
        std::cin >> data[i].avg_score >> data[i].class_score >> xsgb >> xbsf >> data[i].paper_count;
        data[i].xsgb = "Y" == xsgb;
        data[i].xbsf = "Y" == xbsf;
    }
    for (int i = 0; i < N; i++)
    {
        student &s = data[i];
        if (s.avg_score > 80 && s.paper_count >= 1)
            s.scholarship += 8000;
        if (s.avg_score > 85 && s.class_score > 80)
            s.scholarship += 4000;
        if (s.avg_score > 90)
            s.scholarship += 2000;
        if (s.avg_score > 85 && s.xbsf)
            s.scholarship += 1000;
        if (s.class_score > 80 && s.xsgb)
            s.scholarship += 850;
    }
    int total_scholarship = 0;
    int best_student = -1;
    for (int i = 0; i < N; i++)
    {
        total_scholarship += data[i].scholarship;
        if (best_student == -1 || data[i].scholarship > data[best_student].scholarship)
            best_student = i;
    }
    std::cout << data[best_student].name << std::endl;
    std::cout << data[best_student].scholarship << std::endl;
    std::cout << total_scholarship << std::endl;
    return 0;
}
