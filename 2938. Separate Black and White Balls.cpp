class Solution {
public:
    long long minimumSteps(string s) {
        int wht=0;
        long long cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                cnt+=i-wht;
                wht++;
            }
           
        }
         return cnt;
        
    }
};