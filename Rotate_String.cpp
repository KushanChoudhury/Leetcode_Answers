class Solution {
public:
    bool rotateString(string s, string goal) {
        int i=0;
        int n=s.length();
        while(s!=goal&&i<n){
            s=s.substr(1,n-1)+s[0];
            i++;
        }
        if(s==goal)
            return true;
        return false;
    }
};