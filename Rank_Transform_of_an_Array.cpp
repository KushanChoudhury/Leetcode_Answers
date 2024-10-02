class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st(arr.begin(),arr.end());
        unordered_map<int,int> umap;
        int rank=1;
        for(const int& num: st){
            umap[num]=rank++;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=umap[arr[i]];
        }
        return arr;
    }
};