class Solution {
public:
    int guessNumber(int n) {
        long left = 1;
        long right = n;

        while (left <= right) {
            long mid = left + (right - left) / 2;
            int result = guess(mid);

            if (result == 0)
                return mid;
            else if (result == -1)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return -1; 
    }
};