class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            map<int,int> mp;
            int n1=nums1.size();
            int n2=nums2.size();
            for(auto& it:nums1){
                mp[it[0]]=it[1];
            }
            for(auto& it:nums2){
                mp[it[0]]=it[1]+mp[it[0]];
            }
            vector<vector<int>> result;
            for(auto& ele:mp){
                vector<int> sublist;
                sublist.push_back(ele.first);
                sublist.push_back(ele.second);
            
                result.push_back(sublist);
            }
            return result;
        }
    };