class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0) return "";
        int k=0, sn=strs[0].length(), fg=0;
        for(; k<sn; k++)
        {
            for(int i=1; i<n; i++)
            {
                if(strs[i].length()<=k or strs[i-1][k]!=strs[i][k]) 
                {  fg=1; break;}
            }
            if(fg==1) break;
        }
        return strs[0].substr(0, k);
    }
};