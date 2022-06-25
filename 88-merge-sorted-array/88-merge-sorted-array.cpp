class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return ;
        int gap=(m+n)/2;
        for(int i=0; i<n; i++)
        {
            nums1[m+i]=nums2[i];
        }
        while(gap!=0)
        {
            for(int i=0; (i+gap)<(m+n); i++)
            {
                if(nums1[i]>nums1[i+gap])
                    swap(nums1[i], nums1[i+gap]);
            }
            if(gap==1) gap=0;
            else
                gap=ceil(floor(gap)/2);
        }
        
    }
};