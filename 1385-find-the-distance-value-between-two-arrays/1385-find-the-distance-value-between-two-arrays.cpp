class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count1=0,ans=0;
        for(int i=0;i<arr1.size();i++){
            count1=0;
            for(int j=0;j<arr2.size();j++){
                if(abs(arr1[i]-arr2[j])>d){
                    count1++;
                }
                else{
                    break;
                }
            }
            if(count1==arr2.size()){
                ans++;
            }
        }
        return ans;
    }
};