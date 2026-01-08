class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int oddCount = 0;
        int answer = 0;
        int prefixEven = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] % 2 == 1) {
                oddCount++;
                prefixEven = 0;
            }

            while (oddCount == k) {
                prefixEven++;
                if (nums[left] % 2 == 1)
                    oddCount--;
                left++;
            }

            answer += prefixEven;
        }
        return answer;
    }
};
