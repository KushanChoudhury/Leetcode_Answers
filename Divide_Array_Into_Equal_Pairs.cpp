class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            map<int,int> mp;
            for(int i=0;i<nums.size();i++){
                mp[nums[i]]++;
            }
            for(auto &ele: mp){
                if(ele.second%2!=0)
                    return false;
            }
            return true;
        }
    };