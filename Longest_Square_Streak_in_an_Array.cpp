class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxStreak=0;
        unordered_map<int,int> umap;
        for(int & num:nums){
            int root=sqrt(num);
            if(root*root==num&&umap.find(root)!=umap.end()){
                umap[num]=umap[root]+1;
            }
            else{
                umap[num]=1;
            }
            maxStreak=max(maxStreak,umap[num]);
        }
        return maxStreak<2?-1:maxStreak;
    }
};