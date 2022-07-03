class Solution {
public:
    void fsum(vector<int>& candidates, int target, int n, int ind, vector<int> v1 , vector<vector<int>> &ans)
    {
        if(ind==n) return ;
        while(target>=0)
        {
            fsum(candidates, target, n, ind+1, v1, ans); 
            
            target-=candidates[ind];
            v1.push_back(candidates[ind]);
       if(target==0)
            {
                ans.push_back(v1);
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n=candidates.size();
        vector<int> v1;
        int ind=0;
        sort(candidates.begin(), candidates.end());
        fsum(candidates, target, n, ind, v1, ans);
        return ans;
    }
};