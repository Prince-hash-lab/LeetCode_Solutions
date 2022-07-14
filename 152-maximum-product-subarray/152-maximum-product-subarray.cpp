class Solution {
public:
    
    int maxProduct(vector<int>& n) {
      int res=n[0], p1=n[0], p2=n[0];
        for(int i=1; i<n.size(); i++)
        {
            int tp=max({n[i], n[i]*p1,n[i]*p2});
            p2=min({n[i], n[i]*p1,n[i]*p2});
            p1=tp;
            res=max(res, p1);
        }
    
    return res;
    }
};
// const auto fast = []() 
// {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();