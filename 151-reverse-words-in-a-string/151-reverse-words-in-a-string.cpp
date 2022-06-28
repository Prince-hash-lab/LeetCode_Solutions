class Solution {
public:
    string reverseWords(string s) {
        int len=s.length(), start=-1, end=-1;
        stack<string> sts;
        for(int i=0; i<len ; i++)
        {
            if(s[i]==' ' and start!=-1)
            {
                sts.push(s.substr(start, end-start+1));
                start=-1;
                end=-1;
            }
            else if(s[i]!=' ' and start==-1) 
            {
                start=i;  end=i;
            }
            else if(s[i]!=' ' and start!=-1) end++;
        }
        if(start!=-1) sts.push(s.substr(start, end-start+1));
        string ans="";
        while(!sts.empty())
        {
            ans+=sts.top();
            sts.pop();
            if(!sts.empty()) ans+=" ";
        }
        return ans;
        
    }
};