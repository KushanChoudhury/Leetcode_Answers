class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
       int n=matrix.size();
       long long sum=0;
       int countneg=0;
       int smallestabs=INT_MAX;
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum+=abs(matrix[i][j]);
            if(matrix[i][j]<0)
                countneg++;
            smallestabs=min(smallestabs,abs(matrix[i][j]));
        }
       } 
       if(countneg%2==0){
        return sum;
       }
        else{
            return sum-2*smallestabs;
        }
    }
};