class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            map<int,int> mp;
            int n=grid.size();
            vector<int> result;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mp[grid[i][j]]++;
                    if(mp[grid[i][j]]>=2){
                        result.push_back(grid[i][j]);
                    }
                }
            }
            for(int i=1;i<=n*n;i++){
                if(mp.find(i)==mp.end()){
                    result.push_back(i);
                    break;
                }
            }
            return result;
        }
    };