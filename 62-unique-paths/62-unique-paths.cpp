class Solution {
public:
    int uniquePaths(int m, int n) {
        long long N=m+n-2, R=n-1;
        double res=1;
        for(int i=1; i<=R; i++)
            res=res*(N-R+i)/i;
        return res;

    }
};