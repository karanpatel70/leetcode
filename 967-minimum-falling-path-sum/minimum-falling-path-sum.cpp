class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int mini = matrix[i - 1][j];

                if (j > 0) {
                    mini = min(mini, matrix[i - 1][j - 1]);
                }

                if (j + 1 < n) {
                    mini = min(mini, matrix[i - 1][j + 1]);
                }

                matrix[i][j] += mini;
            }
        }

        int ans = matrix[n - 1][0];

        for (int j = 1; j < n; j++) {
            ans = min(ans, matrix[n - 1][j]);
        }
        return ans;
    }
};