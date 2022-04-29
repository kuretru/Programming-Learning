#include <algorithm>

class Solution {
  public:
    vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                int tmp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = tmp;
            }
        }
        for (int i = 0; i < n; i++) {
            std::reverse(mat[i].begin(), mat[i].end());
        }
        return mat;
    }
};
