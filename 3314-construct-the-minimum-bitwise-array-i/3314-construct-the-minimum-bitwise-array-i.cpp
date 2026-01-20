class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int p : nums) {
            int res = -1;
            for (int x = 0; x <= p; x++) {
                if ((x | (x + 1)) == p) {
                    res = x;
                    break;
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};
