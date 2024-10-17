class Solution {
public:
    int maximumSwap(int num) {
        string st=to_string(num);
        int n =  st.size();
        int mx=num;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(st[i],st[j]);
                mx=max(mx,stoi(st));
                swap(st[i],st[j]);
            }
        }
        return mx;
    }
};