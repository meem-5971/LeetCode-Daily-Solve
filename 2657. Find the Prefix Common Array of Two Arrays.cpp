class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>ans(n);
        for(int m=0;m<n;m++){
        int cnt=0;
        for(int i=0;i<=m;i++){
            int x=A[i];
            for(int j=0;j<=m;j++){
                if(B[j]==x){
                    cnt++;
                    break;
                }
            }
        }
        ans[m]=cnt;
        }
        return ans;
    }
};