class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int l = g.size();
        int m = s.size();
        int i = 0,j = 0;
        int cnt=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
       
        while(i<l && j<m){
         if(g[i] <= s[j]){
            cnt++;
            i++;
            j++;
            }
         else if(g[i]>s[j]){
            j++;
         }
        }
        return cnt;
    }
};