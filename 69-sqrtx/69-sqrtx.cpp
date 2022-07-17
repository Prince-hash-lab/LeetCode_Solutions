class Solution {
public:
    int mySqrt(int x) {
        if(x==1 or x==0) return x;
        if(x==2 or x==3) return 1;
        long long int  low=1, high=x/2;
        long long int  mid, ans=-1;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            long long int  st=mid*mid;
            if(st==x) return mid;
            else if(st <x) 
            {  ans=mid; low=mid+1; }
            else high=mid-1;
        }
        return ans;
    }
};