class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        long long int ans=0;
        priority_queue<long long>pq;

        for(auto u:nums){
            pq.push(u);
        }
        while(k--){
            long long mx=pq.top();
            ans+=mx;
            pq.pop();
            pq.push(ceil(mx/3.0));
        }
        return ans;

    }
};