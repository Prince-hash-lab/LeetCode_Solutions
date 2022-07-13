// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++

class triplet
{
    public:
    int val;
    int ind;
    int arind;
        triplet(int a, int b ,int c)
        {
            val=a;  ind=b;  arind=c;
        }
};
struct comp
{
    bool operator()(triplet &t1, triplet &t2)
    {
        return t1.val>t2.val;
    }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        priority_queue<triplet, vector<triplet>, comp> pq;
        for(int i=0 ;i<K; i++)
        {
            if(arr[i].size()!=0)
            {
                triplet t3(arr[i][0], 0, i);
                pq.push(t3);
                // cout<<arr[i][0]<<" ";
            }
        }
        // cout<<endl;
        while(!pq.empty())
        {
            triplet temp=pq.top();
            ans.push_back(temp.val);
            pq.pop();
            
                // cout<<temp.val<<" ";
            if(temp.ind!=arr[temp.arind].size()-1)
            {
                triplet t3(arr[temp.arind][temp.ind+1], temp.ind+1, temp.arind);
                pq.push(t3);
            }
        }
        //code here
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends