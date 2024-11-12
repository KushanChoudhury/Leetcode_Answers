class Solution {
public:
    int customBinSearch(vector<vector<int>>& items,int qp){
        int l=0;
        int r=items.size()-1;
        int mid;
        int maxB=0;
        while(l<=r){
            mid=l+(r-l)/2;
            if(items[mid][00]>qp)
                r=mid-1;
            else{
                maxB=max(maxB,items[mid][1]);
                l=mid+1;
            }
        }
        return maxB;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n =items.size();
        int m = queries.size();
        vector<int> result(m);
        sort(items.begin(),items.end());
        int maxB=items[0][1];
        for(int i=1;i<n;i++){
            maxB=max(maxB,items[i][1]);
            items[i][1]=maxB;
        }
        for(int i=0;i<m;i++){
            int qp=queries[i];
            result[i]=customBinSearch(items,qp);
        }
        return result;
    }
};