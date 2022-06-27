class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size=nums.size();
        if(size==0) return 0;
        unordered_set<int> hs;
        int res=1, longst, val;
        for(int num:nums) hs.insert(num);
        
         for(int num: nums)
         {
             if(hs.count(num-1)==0)
             {
                 longst=1;  val=num;
                 while(hs.count(val+1)!=0)
                 {
                     val++;
                     longst++;
                 }
                 res=max(res, longst);
             }
         }
        return res;
    }
};