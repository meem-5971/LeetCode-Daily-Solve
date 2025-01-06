class Solution {
public:
    vector<int> minOperations(string boxes) {
     
     int n=boxes.size();
     vector<int>ans(n);
     int cumval=0;
     int cumsum=0;

     for(int i=0;i<n;i++){
        ans[i]+=cumsum;
        if(boxes[i]=='1'){
            cumval+=1;
        }
        cumsum+=cumval;
     }

        cumval=0;
        cumsum=0;
     for(int i=n-1;i>=0;i--){
        ans[i]+=cumsum;
         if(boxes[i]=='1'){
            cumval+=1;
        }
        cumsum+=cumval;
     }
return ans;

    }
};