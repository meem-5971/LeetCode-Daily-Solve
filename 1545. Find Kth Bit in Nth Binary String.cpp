class Solution {
public:
    char findKthBit(int n, int k) {
        //start string with 0
        string s1="0";

        
        for(int i=1;i<n;i++){
            //there will be 1 inbetween the inversion and append of 2nd part of string
            s1+='1';

            //taking s2 as reference
        string s2=s1;
        //loop for revserse
        for(int j=s2.length()-2;j>=0;j--){
            char inv;
            //character will be inversed and append
            if(s2[j]=='1'){
                inv='0';
            }
            else{
                inv='1';
            }
            s1+=inv;
        }
        }
        return s1[k-1];
    }
};