class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int s1=nums1.size(), s2=nums2.size();
        stack<int> st;
        st.push(nums2[s2-1]);
        unordered_map<int,int> mp;
        mp[nums2[s2-1]]=-1;
        for(int i=s2-2; i>=0; i--)
        {
            while(!st.empty() and nums2[i]>st.top())
                st.pop();
            if(st.empty()) 
                mp[nums2[i]]=-1; 
            else
                mp[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        for(int i=0; i<s1; i++)
        {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};