class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
     vector<string>res;
        vector<int>mxfq(26,0);
     for(string s:words2){
        vector<int>fq(26,0);
        for(char c: s){
            fq[c-'a']++;
        }
        for(int i=0;i<26;i++){
            mxfq[i]=max(mxfq[i],fq[i]);
        }
     }

     for(string s:words1){
        vector<int>fq(26,0);
        for(char c: s){
            fq[c-'a']++;
        }
        bool flag=true;
        for(int i=0;i<26;i++){
            if(fq[i]<mxfq[i]){
                flag=false;
                break;
            }
        }
        if(flag) res.push_back(s);
     }
     return res;
    }
    
};