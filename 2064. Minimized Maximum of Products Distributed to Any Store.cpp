class Solution {
public:

    bool pssbldstrb(int x,vector<int>& quantities,int shops){
        for(int &prod: quantities){
            shops -=(prod+x-1)/x; //ceil(prod/x);
            if(shops<0) return false;
            

        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();

        int l=1;
        int r =*max_element(begin(quantities),end(quantities));
        int res=0;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(pssbldstrb(mid,quantities,n)){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        } 
        return res;

        
    }
};