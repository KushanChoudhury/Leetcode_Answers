class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int msum=accumulate(rolls.begin(),rolls.end(),0);
        int m=rolls.size();
        int totalSum=(n+m)*mean;
        int nsum=totalSum-msum;
        int equiparts=nsum/n;
        int remainder=nsum%n;
        vector<int> ans;
        if(nsum<n||nsum>6*n)
            return {};
        while(n--){
            int excess=0;
            if(remainder>0){
                excess=1;
                remainder--;
            }
            ans.push_back(excess+equiparts);
        }
        return ans;
    }

};