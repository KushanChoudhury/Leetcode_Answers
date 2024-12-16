class Solution {
public:
    int position(vector<int>& arr){
        int n=arr.size();
        int pos=0;
        for(int i=0;i<n;i++){
            if(arr[i]<arr[pos]){
                pos=i;
            }
        }
        return pos;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--){
            int pos=position(nums);
            nums[pos]=nums[pos]*multiplier;
        }
        return nums;
    }
};