class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
     int n=matrix.size();
     int cnt=0;
     int mn=INT_MAX;
     long long sum=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum+=abs(matrix[i][j]);
            if(matrix[i][j]<0){
                cnt++;
            }
            mn=min(mn,abs(matrix[i][j]));
        }
     } 
     if(cnt &1) sum-=2LL*mn;
     return sum;  
    }
};