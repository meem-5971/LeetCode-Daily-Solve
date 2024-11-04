class Solution {
public:
    string compressedString(string word) {
        string comp="";
        int pos=0;
        int n=word.length();
        while(pos <n ){
            int cnt=0;
            char c=word[pos];
            while(pos<n && cnt<9 && word[pos]==c){
                cnt++;
                pos++;
            }
            comp+=to_string(cnt)+c;
        }
        return comp;
    }
};