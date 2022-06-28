class Solution {
public:
    int minDeletions(string s) {
        int len=s.length();
        unordered_map<char, int> charfreq;
        unordered_map<int, int> freqfreq;
        for(int i=0 ;i<len ; i++)
        {
            charfreq[s[i]]++;
        }
        int maxval=0;
        for(auto x:charfreq)
        {
            freqfreq[x.second]++;
            maxval=max(maxval,x.second);   
        }
        int val=0;
        while(maxval!=0)
        {
            if(freqfreq.find(maxval)!=freqfreq.end() and freqfreq[maxval]!=1)
            {
                val+=freqfreq[maxval]-1;
                freqfreq[maxval-1]+=(freqfreq[maxval]-1);
            }
            maxval--;
        }
        return val;
    }
};