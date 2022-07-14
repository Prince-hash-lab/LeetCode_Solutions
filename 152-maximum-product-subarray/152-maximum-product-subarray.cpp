class Solution {
public:
    
    int maxProduct(vector<int>& n) {
      int res=n[0];
        int sz=n.size();
        vector<int> maxlast(sz, 0), minlast(sz,0);
        maxlast[0]=n[0];
        minlast[0]=n[0];
        for(int i=1; i<n.size(); i++)
        {
            maxlast[i]=max({n[i], maxlast[i-1]*n[i], minlast[i-1]*n[i]});
            minlast[i]=min({n[i], maxlast[i-1]*n[i], minlast[i-1]*n[i]});
            
            res=max(res, maxlast[i]);
        }
    
    return res;
    }
};
// const auto fast = []() 
// {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();