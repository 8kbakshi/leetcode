class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        int xorr = 0;
        for (auto it : freq) {
            if (it.second == 2) {
                xorr = xorr ^ it.first;
            }
        }

        return xorr;
    }
};
