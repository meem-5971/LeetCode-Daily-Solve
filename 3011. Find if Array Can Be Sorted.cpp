class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int setbits= __builtin_popcount(nums[0]);
        int maxi=nums[0];
        int mini=nums[0];

        int prevmax=INT_MIN;

        for(int i=1;i<nums.size();i++){
            if(__builtin_popcount(nums[i])==setbits)
{
    maxi=max(maxi,nums[i]);
    mini=min(mini,nums[i]);
} 
    else{
        if(mini <prevmax) return false;

        prevmax=maxi;
        maxi=nums[i];
        mini=nums[i];

        setbits=__builtin_popcount(nums[i]);
    }

       }
       if(mini <prevmax) return false;
       return true;
    }
};