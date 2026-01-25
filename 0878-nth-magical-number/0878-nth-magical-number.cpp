class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    int nthMagicalNumber(int n, int a, int b) {
        const int MOD = 1000000007;

        long long l = 1;
        long long r = (long long)min(a, b) * n;

        long long lcm = (long long)a / gcd(a, b) * b;

        while (l < r) {
            long long mid = l + (r - l) / 2;
            long long cnt = mid / a + mid / b - mid / lcm;

            if (cnt >= n)
                r = mid;
            else
                l = mid + 1;
        }

        return l % MOD;
    }
};
