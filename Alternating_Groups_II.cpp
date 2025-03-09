class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            colors.insert(colors.end(),colors.begin(),colors.begin()+k-1);
            int j=1;
            int i=0;
            int n=colors.size();
            int result=0;
            while(j<n){
                if(colors[j]==colors[j-1]){
                    i=j;
                    j++;
                    continue;
                }
                if(j-i+1==k){
                    result++;
                    i++;
                }
                j++;
            }
            return result;
        }
    };