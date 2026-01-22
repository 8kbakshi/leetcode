class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       
     int n = nums.size();
     unordered_map<int, int> mp;

    for(int i = 0; i < n; i++) 
    {
        mp[nums[i]]++;
    }

    for(int i = 1; i <= n+1; i++) 
    {
        if(mp.find(i) == mp.end()) 
        {
            return i;
        }
    }
    return -1;
    }
};