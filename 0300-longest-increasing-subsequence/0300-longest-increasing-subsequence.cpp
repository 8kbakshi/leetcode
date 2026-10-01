class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;

        for (int n : nums) {

            if (res.empty() || res.back() < n) {
                res.push_back(n);
            }
            else {
                int left = 0;
                int right = res.size() - 1;

                while (left <= right) {
                    int mid = left + (right - left) / 2;

                    if (res[mid] >= n) {
                        right = mid - 1;
                    }
                    else {
                        left = mid + 1;
                    }
                }

                res[left] = n;
            }
        }

        return res.size();
    }
};