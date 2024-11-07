class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int i=0,n=nums.size();
        int prevMax=INT_MIN,currMin=INT_MAX,currMax=INT_MIN;
        while(i<n){
            int a=__builtin_popcount(nums[i]);
            int b=__builtin_popcount(nums[i]);
            while(i<n && a==b){
                currMin=min(currMin,nums[i]);
                currMax=max(currMax,nums[i]);
                i++;
                if(i<n)
                b=__builtin_popcount(nums[i]);
            }
            if(currMin<prevMax) return 0;
            prevMax=currMax;
            currMin=INT_MAX;
        }
        return 1;
    }
};