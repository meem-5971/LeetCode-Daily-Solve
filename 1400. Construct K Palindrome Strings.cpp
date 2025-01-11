class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();
        if(n==k) return true;
        if(k>n) return false;
        vector<int>fq(26,0);
        for(char &c:s){
            fq[c-'a']++;
        }
        int oddcount=0;

        for(int i=0;i<26;i++){
            if(fq[i]%2==1){
                oddcount++;
            }
        }
        return oddcount<=k;
    }
};