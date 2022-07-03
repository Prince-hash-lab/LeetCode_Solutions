class Solution {
public:
    bool closing(char s)
    {
        return s=='}' or s==']' or s==')';
    }
    bool opening(char s)
    {
        return s=='{' or s=='(' or s=='[';
    }
    bool isValid(string s) {
        stack<char> st;
        int len=s.length();
        for(int i=0; i<len; i++)
        {
            if(st.empty() and closing(s[i])) return false;
            if(opening(s[i])) st.push(s[i]);
            else
            {
                if((st.top()=='(' and s[i]==')')   or  (st.top()=='[' and s[i]==']') or (st.top()=='{' and s[i]=='}')  )
                    st.pop();
                else return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};