class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mp(k,0);
        for(int &nums:arr){
            int rem=((nums%k)+k)%k;
            mp[rem]++;
        }
        if(mp[0]%2!=0){
            return false;
        }
        for(int i=1;i<=k/2;i++){
            int half=k-i;
            if(mp[half]!=mp[i]){
                return false;
            }
        }
        return true;
    }
};