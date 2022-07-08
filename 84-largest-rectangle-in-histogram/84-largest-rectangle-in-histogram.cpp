class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        vector<int> lsml(n, 0), rsml(n, 0);
        stack<int> st;
        int res=0;
        st.push(0); lsml[0]=-1;
        //calculating left smaller for every element
        for(int i=1; i<n; i++)
        {
            if(arr[st.top()]<arr[i])
                lsml[i]=st.top();
            else
            {
                while(!st.empty() and arr[st.top()]>=arr[i])
                    st.pop();
                if(st.empty()) lsml[i]=-1;
                else lsml[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        st.push(n-1); rsml[n-1]=n; 
      
        //calculating right smaller for every element
        for(int i=n-2; i>=0; i--)
        {
            if(arr[st.top()]<arr[i])
                rsml[i]=st.top();
            else
            {
                while(!st.empty() and arr[st.top()]>=arr[i])
                    st.pop();
                if(st.empty()) rsml[i]=n;
                else rsml[i]=st.top();
            }
            st.push(i);
        }
        int val=0;
        for(int i=0; i<n; i++)
        {
            res=max(res, arr[i]+(arr[i]*(i-lsml[i]-1))+(arr[i]*(rsml[i]-i-1)) );
        }
        return res;
    }
};