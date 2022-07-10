class Solution {
public:
     void fsum(vector<int>& candidates, int target, int n, int ind, vector<int> v1,vector<vector<int>> &ans )
    {    
         if(target==0) { ans.push_back(v1); return ;}
         if(target<0) return ;
         for(int i=ind; i<n; i++)
         {
             if(i!=ind and candidates[i]==candidates[i-1]) continue;
             // if(target<0) return;
             v1.push_back(candidates[i]);
             fsum(candidates, target-candidates[i], n, i+1, v1, ans);
             v1.pop_back();
         }
         
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
          vector<vector<int>> ans;
        int n=candidates.size();
        vector<int> v1;
        int ind=0;
        sort(candidates.begin(), candidates.end());
        fsum(candidates, target, n, ind, v1, ans);
        return ans;
    }
};