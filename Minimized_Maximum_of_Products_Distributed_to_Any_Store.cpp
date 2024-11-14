class Solution {
public:
    int isPossible(int mid,vector<int>& quantities,int n){
        for(int& product:quantities){
            n-=(product+mid-1)/mid;
            if(n<0)
                return false;
        }
        return true;

    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1;
        int r=*max_element(quantities.begin(),quantities.end());
        int mid;
        int result=0;
        while(l<=r){
            mid=l+(r-l)/2;
            if(isPossible(mid,quantities,n)){
                result=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
};