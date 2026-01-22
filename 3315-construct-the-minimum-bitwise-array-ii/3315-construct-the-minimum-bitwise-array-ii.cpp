class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            int p = nums[i];

            if (p % 2 == 0) {
                ans[i] = -1;
            } else {
                int t = 0;
                int temp = p;

                while (temp & 1) {
                    t++;
                    temp >>= 1;
                }

                ans[i] = p - (1 << (t - 1));
            }
        }
        return ans;
    }
};
