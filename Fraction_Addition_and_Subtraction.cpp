class Solution {
public:
    string fractionAddition(string expression) {
        int num=0;
        int den=1;
        for(int i=0;i<expression.size();){
            int currN=0;
            int currD=0;
            bool isNeg=expression[i]=='-';
            if(expression[i]=='+'||expression[i]=='-')
                i++;
            while(i<expression.length()&&isdigit(expression[i])){
                int val=expression[i]-'0';
                currN=currN*10+val;
                i++;
            }
            i++;
            if(isNeg==true){
                currN*=-1;
            }
            while(i<expression.length()&&isdigit(expression[i])){
                int val=expression[i]-'0';
                currD=currD*10+val;
                i++;
            }
            num=num*currD+currN*den;
            den=den*currD;
        }
        int gcd=abs(__gcd(num,den));
        num/=gcd;
        den/=gcd;
        return to_string(num)+'/'+to_string(den);
    }
};