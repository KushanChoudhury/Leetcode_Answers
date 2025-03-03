class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int> small;
            vector<int> same;
            vector<int> large;
            int n=nums.size();
            for(int i=0;i<n;i++){
                if(nums[i]<pivot){
                    small.push_back(nums[i]);
                }
                else if(nums[i]>pivot){
                    large.push_back(nums[i]);
                }
                else{
                    same.push_back(nums[i]);
                }
            }
            vector<int> result;
            for(int i=0;i<small.size();i++){
                result.push_back(small[i]);
            }
            for(int i=0;i<same.size();i++){
                result.push_back(same[i]);
            }
            for(int i=0;i<large.size();i++){
                result.push_back(large[i]);
            }
            return result;
        }
    };