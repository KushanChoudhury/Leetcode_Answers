class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum=accumulate(chalk.begin(),chalk.end(),0LL);
        if(k%sum!=0){
        long long int remainingchalks=k%sum;
        int i;
        for(i=0;i<chalk.size();i++){
            if(remainingchalks>chalk[i]){
            remainingchalks-=chalk[i];
            }
            else{
                break;
            }
        } 
        if(remainingchalks!=0){
            return i;
        }
        }
        return 0;
    }
};