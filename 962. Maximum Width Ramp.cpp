class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int>id(n);

        for(int i=0;i<n;i++){
            id[i]=i;
        }

    //sorting the indices according to values, if values are same, the low index gets priority
        sort(id.begin(),id.end(),[&](int i,int j){
            if(nums[i]!=nums[j]){
                return nums[i]<nums[j];
            }
            else{
                return i<j;
            }
        });

        int mnid=n;
        int ans=0;
    //from sorted indices
        for(int i=0;i<n;i++){
            ans=max(ans,id[i]-mnid);
            mnid=min(mnid,id[i]);
        }

        return ans;
    }
};