class Solution {
public:
    int minPartitions(string n) {
        int len=n.length();
        char val='0';
        for(int i=0; i<len; i++)
        {
            if(n[i]>val) val=n[i];
        }
        return val-'0';
    }
};