class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int>s;
        long long curr_sum=0;
        long long res=0;
        int i=0,j=0;
        int n=nums.size();

        while(j<n){
            while(s.count(nums[j])){
                curr_sum-=nums[i];
                s.erase(nums[i]);
                i++;
            }

            curr_sum+=nums[j];
            s.insert(nums[j]);
            if(j-i+1==k){
                res=max(res,curr_sum);
                curr_sum-=nums[i];
                s.erase(nums[i]);
                i++;
            }
            j++;
        }
        return res;
    }
};