class Solution {
public:
    int minChanges(string s) {
     char c=s[0];
    int cnt=0;
    int req=0;
     for(int i=0;i<s.length();i++){
        if(s[i]==c){
            cnt++;
            continue;
        }

        if(cnt%2==0){
            cnt=1;
        }
        else{
            cnt=0;
            req++;
        }
        c=s[i];

     }
     return req;   
    }
};