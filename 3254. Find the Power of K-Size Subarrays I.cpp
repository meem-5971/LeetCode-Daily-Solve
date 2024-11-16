class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
       int cnt=0;
       vector<int>ans;
       int n=nums.size();
       for(int i=0;i<=n-k;i++){
        int p=nums[i];
        int t=0;
        for(int j=i+1;j<i+k;j++){
                if(nums[j]==p+1){
                    t++;
                    
                }
                p=nums[j];
        }
        if(t==k-1){
            cnt++;
            ans.push_back(nums[i+k-1]);
        }
        else{
            ans.push_back(-1);
        }
       } 
       return ans;
    }
};