class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> umap;
        int m=matrix.size();
        int n=matrix[0].size();
        for(auto &row: matrix){
            string rowKnature="";
            int firstVal=row[0];
            for(int col=0;col<n;col++){
                rowKnature+=(row[col]==firstVal)?'S':'B';
            }
            umap[rowKnature]++;
        }
        int maxrows=0;
        for(auto &it:umap){
            maxrows=max(maxrows,it.second);
        }
        return maxrows;
    }
};