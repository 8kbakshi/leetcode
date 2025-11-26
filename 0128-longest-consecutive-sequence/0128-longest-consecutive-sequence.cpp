class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for(int num : st) {

            if(st.find(num - 1) == st.end()) {
                int curr = num;
                int count = 1;

                while(st.find(curr + 1) != st.end()) {
                    curr++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};
