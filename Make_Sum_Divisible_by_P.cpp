class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum=0;
        for(int& num:nums){
            sum=(sum+num)%p;
        }
        int target =sum%p;
        if(target==0){
            return 0;
        }
        unordered_map<int,int> umap;
        int result=nums.size();
        int curr=0;
        umap[0]=-1;
        for(int i=0;i<nums.size();i++){
            curr=(curr+nums[i])%p;
            int remainder=(curr-target+p)%p;
            if(umap.find(remainder)!=umap.end()){
                result=min(result,i-umap[remainder]);
            }
            umap[curr]=i;
        }
        return result==nums.size()?-1:result;
    }
};