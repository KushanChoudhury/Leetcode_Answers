class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector <int> ans={-1000000,1000000};
        int k=nums.size();
        int maxval=INT_MIN;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<k;i++){
            int elements=nums[i][0];
            vector<int> temp{elements,0,i};
            maxval=max(maxval,elements);
            pq.push(temp);
        }
        while(true){
            vector<int> minval=pq.top();
            pq.pop();
            if(ans[1]-ans[0]>maxval-minval[0]){
                ans[0]=minval[0];
                ans[1]=maxval;
            }
            minval[1]++;
            vector<int> cl=nums [minval[2]];
            if(minval[1]==cl.size()){
                break;
            }else{
                minval[0]=cl[minval[1]];
                maxval=max(maxval, cl[minval[1]]);
                pq.push(minval);
            }
        }
        return ans;
    }
};