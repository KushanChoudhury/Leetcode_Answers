class Solution {
    public:
        void flipOp(vector<int>& nums,int i){
            nums[i]^=1;
            nums[i+1]^=1;
            nums[i+2]^=1;
        }
        int minOperations(vector<int>& nums) {
            int n =nums.size();
            int c=0,i;
            for(i=0;i<n-2;i++){
                if(nums[i]==0){
                    flipOp(nums,i);
                    c++;
                }
            }
            if(nums[i]==0||nums[i+1]==0)
                return -1;
            return c;
        }
    };