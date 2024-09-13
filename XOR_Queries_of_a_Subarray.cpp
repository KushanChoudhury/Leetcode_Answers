class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        for(auto& pr:queries){
            int left=pr[0];
            int right=pr[1];
            int xorval=0;
            for(int i=left;i<=right;i++){
                xorval^=arr[i];
            }
            result.push_back(xorval);
        }
        return result;
    }
};