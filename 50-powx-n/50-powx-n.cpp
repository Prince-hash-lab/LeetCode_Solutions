class Solution {
public:
    double myPow(double x, int n) {
        if(x==1) return x;
        long long n1=abs(n);
        double ans=1;
        while(n1!=0)
        {
            if(n1%2==0)
            {
                x=x*x;
                n1=ceil(float(n1)/2);
            }
            else 
            {
                ans*=x;
                n1--;
            }
        }
        if(n<0) ans=(1/ans);
        return ans;
    }
};