class Solution {
public:
    int longestPalindrome(string s) {
        int oddCount = 0;
        unordered_map<char, int> ab;
        for(char ch : s) {
         ab[ch]++;
            if (ab[ch] % 2 == 1)
                oddCount++;
            else    
                oddCount--;
        }
        if (oddCount > 1)
            return s.length() - oddCount + 1;
        return s.length();
    }
};