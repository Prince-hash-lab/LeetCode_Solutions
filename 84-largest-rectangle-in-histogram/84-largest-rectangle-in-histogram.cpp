class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
       
        stack<int> st;
        int res=0, back, front, ele;
        st.push(0);
        //calculating left smaller for every element
        for(int i=1; i<n; i++)
        {
            if(arr[st.top()]<=arr[i]) 
            { st.push(i); continue;}
           while(!st.empty() and arr[st.top()]>arr[i]) 
           {
               ele=st.top();
               st.pop();
               back=st.empty()?-1:st.top();
               res=max(res, arr[ele]+(arr[ele]*(ele-back-1))+(arr[ele]*(i-ele-1)));
               
           }
           st.push(i);
        }
        while(!st.empty())
        {   ele=st.top();
            st.pop();
            back=st.empty()?-1:st.top();
            res=max(res, arr[ele]+(arr[ele]*(ele-back-1))+(arr[ele]*(n-ele-1)));
        }
       
        return res;
    }
    
};


const auto fast = []() 
{std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();