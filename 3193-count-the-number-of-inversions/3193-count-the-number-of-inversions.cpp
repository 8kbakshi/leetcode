class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        const int MOD = 1e9 + 7;
        const int MAX_INV = 400;

        vector<int> need(n, -1);
        for (auto &r : requirements)
            need[r[0]] = r[1];

        vector<vector<int>> dp(n + 1, vector<int>(MAX_INV + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            vector<int> pref(MAX_INV + 2, 0);
            for (int j = 0; j <= MAX_INV; j++)
                pref[j + 1] = (pref[j] + dp[i - 1][j]) % MOD;

            for (int j = 0; j <= MAX_INV; j++) {
                int l = max(0, j - (i - 1));
                int r = j;
                dp[i][j] = (pref[r + 1] - pref[l] + MOD) % MOD;
            }

            if (need[i - 1] != -1) {
                for (int j = 0; j <= MAX_INV; j++)
                    if (j != need[i - 1]) dp[i][j] = 0;
            }
        }

        int ans = 0;
        for (int j = 0; j <= MAX_INV; j++)
            ans = (ans + dp[n][j]) % MOD;

        return ans;
    }
};
