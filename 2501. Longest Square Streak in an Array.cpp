class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int>mp;
        int mx=0;
        for(auto n: nums){
            int root =(int)sqrt(n);

            if(root*root==n && mp.find(root)!=mp.end()){
                mp[n]=mp[root]+1;
            }
            else{
                mp[n]=1;
            }
            mx=max(mp[n],mx);
        }

        if(mx>=2) return mx;
        else return -1;

    }
};