class Solution {
public:
    int countSubsets(int idx,int currOr,int maxOr,vector<int>& nums,vector<vector<int>>& t){
        if(idx==nums.size()){
            if(currOr==maxOr){
                return 1;
            }
            return 0;
        }
        if(t[idx][currOr]!=-1){
            return t[idx][currOr];
        }
        int taken=countSubsets(idx+1,currOr|nums[idx],maxOr,nums,t);
        int nottaken=countSubsets(idx+1,currOr,maxOr,nums,t);
        return t[idx][currOr]=taken+nottaken;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr=0;
        for(int &num:nums){
            maxOr|=num;
        }
        int currOr=0;
        vector<vector<int>> t(nums.size()+1,vector<int>(maxOr+1,-1));
        return countSubsets(0,currOr,maxOr,nums,t);
    }
};