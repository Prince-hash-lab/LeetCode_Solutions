class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        // vecto
        vector<vector<int>> ans;
        // ans.push_back(arr[0]);
        // int ind=0;
        for(int i=0; i<arr.size(); i++)
        {
           if(ans.empty()) 
           {
               ans.push_back(arr[i]);
               continue;
           }
            if(ans.back()[1]>=arr[i][0])
            {
                ans.back()[1]=max(ans.back()[1], arr[i][1]);
            }
            else
                ans.push_back(arr[i]);
            
        }
        return ans;
    }
};