class Solution {
public:
    bool isCircularSentence(string sentence) {
        for(int i=0;i<sentence.length();i++){
            if(i==sentence.length()-1){
                if(sentence[0]!=sentence[i]){
                    return false;
                }
            }
            if(sentence[i]==' '){
                if(sentence[i-1]!=sentence[i+1]){
                    return false;
                }
            }
        }
        return true;
    }
};