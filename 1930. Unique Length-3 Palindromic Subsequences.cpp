class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.length();
        unordered_set<char>letters;
        for(int i=0;i<n;i++){
            letters.insert(s[i]);
        }
        int res=0;
        for(auto c:letters){
            int left_id=-1;
            int right_id=-1;

            for(int i=0;i<n;i++){
                if(s[i]==c){
                    if(left_id==-1){
                        left_id=i;
                    }
                    else{
                        right_id=i;
                    }
                }
            }
             
        unordered_set<char>found;
        for(int i=left_id+1;i<=right_id-1;i++){
            found.insert(s[i]);
        }
        res+=found.size();
        }

        return res;       

    }
};