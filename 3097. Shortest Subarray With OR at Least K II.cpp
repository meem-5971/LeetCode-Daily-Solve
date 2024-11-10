class Solution {
public:

    void updateWindow(int number, vector<int>&vec,int val){
     for(int i=0;i<32;i++){
        if((number >>i) & 1){
            vec[i]+=val;
        }
     }   
    }
    int getDecimal(vector<int>&vec){
        int num=0;
        for(int i=0;i<32;i++){
            if(vec[i]>0){
                num |=(1 << i);
            }
        }
        return num;

    }
   
    int minimumSubarrayLength(vector<int>& nums, int k) {
       int n=nums.size();

       int result=INT_MAX;
       int i=0,j=0;

       vector<int>vec(32,0);

       while(j<n){
        updateWindow(nums[j],vec,1); //adding in  current window

        while(i<=j && getDecimal(vec)>=k){
            result=min(result,j-i+1);
            updateWindow(nums[i],vec,-1); //remove nums[i] from window
            i++;
        }
        j++;
       }
       return result == INT_MAX ? -1 : result;

    }
};