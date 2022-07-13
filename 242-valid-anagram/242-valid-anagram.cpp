class Solution {
public:
     bool isAnagram(string s, string t) {
        int n1=s.length(), n2=t.length();
        if(n1!=n2) return false;
        vector<int> mp(256, 0);
        for(int i=0; i<n1; i++)
        {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto x: mp)
        {
            if(x!=0) return false;
        }
        return true;
    }
// };
};