class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1e9 + 7;

        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> h;
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                h.insert(hFences[j] - hFences[i]);
            }
        }

        long long ans = -1;
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int d = vFences[j] - vFences[i];
                if (h.count(d)) {
                    ans = max(ans, 1LL * d * d);
                }
            }
        }

        if (ans == -1) return -1;
        return ans % MOD;
    }
};
