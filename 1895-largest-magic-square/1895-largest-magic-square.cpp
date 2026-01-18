class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxK = min(m, n);

        for (int k = maxK; k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {

                    int target = 0;
                    for (int c = 0; c < k; c++) {
                        target += grid[i][j + c];
                    }

                    bool ok = true;

                    for (int r = 0; r < k && ok; r++) {
                        int sum = 0;
                        for (int c = 0; c < k; c++) {
                            sum += grid[i + r][j + c];
                        }
                        if (sum != target) ok = false;
                    }

                    for (int c = 0; c < k && ok; c++) {
                        int sum = 0;
                        for (int r = 0; r < k; r++) {
                            sum += grid[i + r][j + c];
                        }
                        if (sum != target) ok = false;
                    }

                    int diag1 = 0;
                    for (int d = 0; d < k; d++) {
                        diag1 += grid[i + d][j + d];
                    }
                    if (diag1 != target) ok = false;

                    int diag2 = 0;
                    for (int d = 0; d < k; d++) {
                        diag2 += grid[i + d][j + k - 1 - d];
                    }
                    if (diag2 != target) ok = false;

                    if (ok) return k;
                }
            }
        }
        return 1;
    }
};
