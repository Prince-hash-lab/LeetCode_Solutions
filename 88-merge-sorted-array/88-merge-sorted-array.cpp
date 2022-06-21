class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ind1=0, ind2=0, ind=0;
        vector<int> temp(m+n);
        while(ind1<m and ind2<n)
        {
            if(nums1[ind1]<nums2[ind2]) temp[ind++]=nums1[ind1++];
            else temp[ind++]=nums2[ind2++];
        }
        while(ind1<m) temp[ind++]=nums1[ind1++];
        while(ind2<n) temp[ind++]=nums2[ind2++];
        ind--;
        // for(int i=0 ;i<ind; i++) nums1[i]=temp[i];
        while(ind>=0)
        {
            nums1[ind--]=temp[ind];
        }
        // return nums1;
    }
};