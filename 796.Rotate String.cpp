class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        int m=goal.size();

        for(int i=0;i<n;i++){
            if(s==goal){
                return true;
            }
            char last =s.back();
            s.pop_back();
            s=last+s;

        }
        return false;
    }
};
#using rotate functions
for (int rotationCount = 0; rotationCount < length; ++rotationCount) {
            // Perform one rotation
            rotate(s.begin(), s.begin() + 1, s.end());
            if (s == goal) return true;
        }