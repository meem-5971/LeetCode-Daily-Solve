class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        vector<int>fq(26,0);

        for(int i=0;i<n;i++){
            fq[s[i]-'a']++;
            if(fq[s[i]-'a']==3){
                fq[s[i]-'a']-=2;
            }
        }
        int res=0;
        for(int i=0;i<26;i++){
            res+=fq[i];
        }
        return res;
    }
};