class Solution {
public:
    int getLucky(string s, int k) {
        string charnum="";
        for(char &c:s){
            int mod=c-'a'+1;
            charnum+=to_string(mod);
        }
        int sum=0;
        for(char& c:charnum){
            sum+=c-'0';
        }
        k--;
        while(k>=1){
            int tempsum=0;
            while(sum>0){
                tempsum+=sum%10;
                sum=sum/10;
            }
            sum=tempsum;
            k--;
        }
        return sum;
    }
};