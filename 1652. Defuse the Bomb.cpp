//BruteForce

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> result(code.size(), 0);
        if (k == 0) {
            return result;
        }
        for (int i = 0; i < result.size(); i++) {
            if (k > 0) {
                for (int j = i + 1; j < i + k + 1; j++) {
                    result[i] += code[j % code.size()];
                }
            } else {
                for (int j = i - abs(k); j < i; j++) {
                    result[i] += code[(j + code.size()) % code.size()];
                }
            }
        }
        return result;
    }
};


//SlidingWindow
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
       int n=code.size();
       vector<int>result(n,0);
       if(k==0){
        return result;
       }
       int i=-1,j=-1;
       if(k>0){
            i=1;
            j=k;
       }
       else {
            i = n - abs(k);
            j = n-1;
        }
          int windowSum = 0;
        for(int pointer = i; pointer <= j; pointer++) {
            windowSum += code[pointer];
        }

        for(int k = 0; k < n; k++) { //result[k]
            result[k] = windowSum;

            windowSum -= code[i % n];
            i++;

            windowSum += code[(j+1)%n];
            j++;
        }

        return result;
    }
};