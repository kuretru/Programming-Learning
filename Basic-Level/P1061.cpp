#include <iostream>
using namespace std;
struct question
{
    int score;
    int answer;
};
int main()
{
    int N, M;
    cin >> N >> M;
    question *data = new question[M];
    for (int i = 0; i < M; i++)
        cin >> data[i].score;
    for (int i = 0; i < M; i++)
        cin >> data[i].answer;
    while (N--)
    {
        int key, result = 0;
        for (int i = 0; i < M; i++)
        {
            cin >> key;
            if (key == data[i].answer)
                result += data[i].score;
        }
        cout << result << endl;
    }
    return 0;
}
