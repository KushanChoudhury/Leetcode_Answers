class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n =nums.size();

        vector<int> result(n);
        int XOR=0;
        for(int i=0;i<n;i++){
            XOR^=nums[i];
        }
        int maskbit=(1<<maximumBit) -1;
        for(int i=0;i<n;i++){
            int k=XOR^maskbit;
            result[i]=k;
            XOR^=nums[n-i-1];
        }
        return result;
    }
};