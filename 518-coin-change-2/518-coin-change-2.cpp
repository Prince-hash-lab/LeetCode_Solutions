class Solution {
public:
     int cc(vector<int>& cn, int amt, int i , int n, vector<vector<int>> &v)
    {
        if(v[i][amt]!=-1) return v[i][amt];
        if(i==n)
        {
            if(amt==0) return 1;
            else return 0;
        }
         int val=cc(cn, amt, i+1, n, v);
         if(cn[i]<=amt)
             val+=cc(cn, amt-cn[i], i, n, v);
         return v[i][amt]=val;
    }
    int change(int amt, vector<int>& cn) {
         int n=cn.size();
        vector<vector<int>> v(n+1, vector<int> (amt+1, -1));
       return cc(cn, amt, 0, n, v);
    }
};