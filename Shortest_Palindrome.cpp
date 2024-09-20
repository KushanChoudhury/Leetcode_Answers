class Solution {
public:
    void computeLPS(string & pattern, vector<int>& lps){
        int N=pattern.length();
        int i=1;
        int len=0;
        lps[0]=0;
        while(i<N){
            if(pattern[i]==pattern[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string revStr=s;
        reverse(revStr.begin(),revStr.end());
        string str=s+"#"+revStr;
        int N=str.length();
        vector<int> lps(N,0);
        computeLPS(str,lps);
        int longestLpsLen=lps[N-1];
        return revStr.substr(0,s.length()-longestLpsLen)+s;
    }
};