class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1=haystack.length();
        int n2=needle.length();
        if(n2>n1) return -1;
        int ind=-1;
        for(int i=0; i<=n1-n2; i++)
        {   int j=0;
            for(; j<n2; j++)
            {
                if(haystack[i+j]!=needle[j])
                    break;
            }
         if(j==n2)
         {
             ind=i;
             break;
         }
        }
        return ind;
    }
};