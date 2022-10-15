class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if(arr.size()==0 or arr.size()==1) return arr.size();
        unordered_set<int> st;
        for(auto x: arr) st.insert(x);
        int res=1;
        int n=arr.size();
        for(int i=0; i<n; i++)
        {
            int curr=1;
            if(st.find(arr[i]-1)==st.end())
            {
                while(st.find(arr[i]+curr)!=st.end())
                {
                    curr++;
                    res=max(res, curr);
                }
            }
        }
        return res;
    }
};