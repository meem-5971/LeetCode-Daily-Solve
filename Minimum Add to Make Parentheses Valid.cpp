class Solution {
public:
    int minAddToMakeValid(string s) {
        int op=0;
        int req=0;
     //Ans = the number of opening brackets which do not have closing brackets + the number of closing brackets which do not have opening brackets
        for(char c:s){
            if(c=='('){
                op++;
            }
            else{
                //for each closing bracket, we will decrease the number of opening brackets
                if(op>0){
                    op--;
                }
                //if there's no opening bracket for closing bracket, we will require one open bracket
                else{
                    req++;
                }
            }
        }
        // the leftover opening brackets which do not have closing brackets will be added to ans
        return op+req;

    }
};