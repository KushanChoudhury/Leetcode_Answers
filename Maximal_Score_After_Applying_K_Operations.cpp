class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum=0;
        priority_queue<int> pq(nums.begin(),nums.end());
        while(k--){
            int maxele=pq.top();
            pq.pop();
            sum+=maxele;
            maxele=ceil(maxele/3.0);
            pq.push(maxele);
        }
        return sum;
    }
};