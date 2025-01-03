class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long int> sumarr(n);
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            sumarr[i]=sum;
        }
        int c=0;
        for(int i=0;i<n-1;i++){
            if(sumarr[i]>=sumarr[n-1]-sumarr[i])
                c++;
        }
        return c;
    }
};