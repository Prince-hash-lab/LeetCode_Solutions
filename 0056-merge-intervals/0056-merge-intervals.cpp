class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        int curr=0;
        for(int i=1; i<arr.size(); i++)
        {
            if(ans[curr][1]>=arr[i][0]) ans[curr][1]=max(ans[curr][1], arr[i][1]);
                else
                {
                    ans.push_back(arr[i]);
                    curr++;
                }
        }
        return ans;
    }
};