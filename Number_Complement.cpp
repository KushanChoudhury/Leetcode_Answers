class Solution {
public:
    string num2bin(int num){
        string res="";
        while(num>0){
            res=to_string(num%2)+res;
            num/=2;
        }
        return res.empty()?"0":res;
    }

    int binary2num(string& bin) {
        int res = 0;
        int len = bin.length();
        for (int i = 0; i < len; ++i) {
            if (bin[i] == '1') {
                res += (1 << (len - 1 - i)); 
            }
        }
        return res;
    }
    int findComplement(int num) {
        string bin=num2bin(num);
        for(char &c:bin){
            c=c=='0'?'1':'0';
        }
        return binary2num((bin));
    }
};