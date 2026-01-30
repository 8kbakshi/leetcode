class Solution {
public:
    bool isPerfectSquare(int x) {
        int low=1,high=x;
        bool ans=true;
        if(x==0 || x==1) 
        return true;
      
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid==x/mid && x%mid==0) 
            return true;
            else if(mid<x/mid){
                ans=false;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};