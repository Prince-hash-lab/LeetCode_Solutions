class Solution {
public:
    int trap(vector<int>& height) {
        int sz=height.size();
        vector<int> leftmax(sz);
        vector<int> rightmax(sz);
        
        int water=0;
        rightmax[sz-1]=height[sz-1];
        leftmax[0]=height[0];
        for(int i=sz-2; i>=0; i--)
        {
            rightmax[i]=max(height[i], rightmax[i+1]);
        }
        for(int i=1; i<sz-1; i++)
        {
            leftmax[i]=max(height[i], leftmax[i-1]);
        }
        int val=0;
        for(int i=1; i<sz-1; i++)
        {
            val=min(leftmax[i], rightmax[i]);
            if(val<height[i]) continue;
            else water+=(val-height[i]);
        }
        return water;
    }
};