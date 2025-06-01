class Solution {
public:
    long long distributeCandies(int n, int limit) {
        int ch1mn=max(0,n-2*min(n,limit));
        int ch1mx=min(n,limit);
        long long ways=0;
        for(int i=ch1mn;i<=ch1mx;i++){
            int N=n-i;
            int ch2mn=max(0,N-limit);
            int ch2mx=min(N,limit);
            ways+=(ch2mx-ch2mn+1);

        }
        return ways;

    }
};