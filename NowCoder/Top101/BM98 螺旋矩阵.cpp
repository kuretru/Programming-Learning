#include <vector>

const int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const int difference[4][4] = {{1, 0, 0, 0}, {0, 0, 0, -1}, {0, -1, 0, 0}, {0, 0, 1, 0}};

class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        int m = matrix.size();
        int n = m > 0 ? matrix[0].size() : 0;
        int length[] = {0, m - 1, 0, n - 1};
        int step = 0;
        point p;
        vector<int> result;
        for (int i = m * n; i > 0; i--) {
            result.push_back(matrix[p.x][p.y]);
            p = next(length, step, p);
        }
        return result;
    }
  private:
    struct point {
        int x = 0;
        int y = 0;
    };
    point next(int length[], int &step, point &p) {
        int x = p.x + direction[step][0];
        int y = p.y + direction[step][1];
        if (x < length[0] || x > length[1] || y < length[2] || y > length[3]) {
            for (int i = 0; i < 4; i++) {
                length[i] += difference[step][i];
            }
            step = (step + 1) % 4;
        }
        p.x += direction[step][0];
        p.y += direction[step][1];
        return p;
    }
};
