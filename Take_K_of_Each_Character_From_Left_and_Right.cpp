class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.length();
        int c_a=0;
        int c_b=0;
        int c_c=0;

        for(char &ch :s){
            if(ch=='a')
                c_a++;
            else if(ch=='b')
                c_b++;
            else
                c_c++;
        }
        if(c_a<k||c_b<k||c_c<k){
            return -1;
        }
        int i=0;
        int j=0;
        int notDeletedWindowSize = 0;
        while(j<n){
            if(s[j] == 'a') {
                c_a--;
            } else if(s[j] == 'b') {
                c_b--;
            } else if(s[j] == 'c') {
                c_c--;
            }

            //if deletion count of any character becomes less than k, then shrink the window and bring them back
            while(i <= j && (c_a < k || c_b < k || c_c < k)) {
                //ith pointer move to left
                if(s[i] == 'a') {
                    c_a++;
                } else if(s[i] == 'b') {
                    c_b++;
                } else {
                    c_c++;
                }
                i++;
            }
            notDeletedWindowSize = max(notDeletedWindowSize, j-i+1);
            j++;
        }
        return n - notDeletedWindowSize;
        
    }
};