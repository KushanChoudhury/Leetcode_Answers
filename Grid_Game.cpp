class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowRemSum=accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long secondRowRemSum=0;
        long long minRobot2Sum=LONG_LONG_MAX;
        for(int i=0;i<grid[0].size();i++){
            firstRowRemSum-=grid[0][i];
            long long bestOfRobot2=max(firstRowRemSum,secondRowRemSum);
            minRobot2Sum=min(minRobot2Sum,bestOfRobot2);
            secondRowRemSum+=grid[1][i];
        }
        return minRobot2Sum;
    }
};