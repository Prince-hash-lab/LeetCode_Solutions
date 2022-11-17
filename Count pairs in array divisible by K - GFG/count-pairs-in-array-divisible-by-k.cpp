//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int k)
    {
        long long count=0;
        vector<int> freq(k, 0);
        unordered_set<int> st;
        for(int i=0; i<n ;i++)
        {
            freq[A[i]%k]+=1;
        }
        if(freq[0])
        count+=(freq[0]*(freq[0]-1))/2;
        for(int i=1; i<k; i++)
        {
            if(k-i==i)
            {
                count+=((freq[i]-1)*freq[i])/2;
            }
            else if(st.count(k-i))
            {
                 count+=((freq[k-i])*freq[i]);
            }
                st.insert(i);
                // cout<<k-i<<" ";
                // cout<<i<<" "<<freq[i]<<" "<<count<<endl;
        }
        return count;
        //code here
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}

// } Driver Code Ends