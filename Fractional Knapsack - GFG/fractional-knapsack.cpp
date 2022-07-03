// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
bool compare(Item i1, Item i2)
{
    return (double)i1.value/i1.weight > (double)i2.value/i2.weight;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double prof=0;
        sort(arr, arr+n, compare);
        for(int i=0; i<n and W>0; i++)
        {
            if(W>=arr[i].weight)
            {
                W-=arr[i].weight;
                prof+=(double)arr[i].value;
            }
            else
            {
                prof+=((double)arr[i].value/arr[i].weight)*(W);
                W=0;
            }
        }
        return prof;
        // Your code here
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends