class KthLargest {
    priority_queue<int, vector<int>, greater<int> > pq;
    int kth;
public:
    //  1 2 3 4  5 6 7  --->k =3
    //  0 1 2 3  4 5 6 
    KthLargest(int k, vector<int>& nums) {
        kth=k;
        if(!nums.size()) return ;
        for(int i=0; i<k and i<nums.size(); i++)
        {
            pq.push(nums[i]);
        }
       for(int i=k; i<nums.size(); i++)
       {
           pq.push(nums[i]);
           pq.pop();
       }
    }
    
    int add(int val) {
        pq.push(val); 
        if(pq.size()>kth)
        pq.pop();
        return pq.top();
    }
};
const auto fast = []() 
{std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */