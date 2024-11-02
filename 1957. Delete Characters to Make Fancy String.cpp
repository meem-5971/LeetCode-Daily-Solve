class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int j=1;
        ans.push_back(s[0]);
        char prev=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]==prev){
               
                j++;
            }
            else{
                prev=s[i];
                j=1;
            }
            if(j<3) ans.push_back(s[i]);
        }
        return ans;
    }
};