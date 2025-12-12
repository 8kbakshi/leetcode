class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int pref = 0, cnt = 0;
        for(int x : nums){
            pref += x;
            if(mp.count(pref - k)) cnt += mp[pref - k];
            mp[pref]++;
        }
        return cnt;
    }
};
