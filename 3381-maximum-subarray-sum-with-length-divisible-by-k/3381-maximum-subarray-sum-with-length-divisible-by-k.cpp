class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n+1, 0);
        
        for (int i = 0; i < n; i++)
            pref[i+1] = pref[i] + nums[i];

        vector<long long> best(k, LLONG_MAX);
        best[0] = 0;

        long long ans = LLONG_MIN;

        for (int j = 1; j <= n; j++) {
            int mod = j % k;

            if (best[mod] != LLONG_MAX)
                ans = max(ans, pref[j] - best[mod]);

            best[mod] = min(best[mod], pref[j]);
        }

        return ans;
    }
};
