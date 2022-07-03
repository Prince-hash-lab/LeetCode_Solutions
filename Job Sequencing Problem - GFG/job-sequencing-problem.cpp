// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
bool compare(Job j1, Job j2)
{
  return j1.profit>j2.profit;
    
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        if(n==0) return {0,0};
        sort(arr, arr+n, compare);
        int prof=0, num=0, maxdead=arr[0].dead;
        for(int i=0; i<n; i++)  maxdead=max(maxdead, arr[i].dead);
        
        vector<int> temp(maxdead+1, -1);
        
        for(int i=0; i<n; i++)
        {
           int profval=arr[i].profit, deadval=arr[i].dead;
           while(deadval>0)
           {
               if(temp[deadval]==-1) break;
               deadval--;
           }
           if(deadval!=0) 
           {
               prof+=profval;
               temp[deadval]=1;
               num++;
           }
        }
       return {num, prof};
        // your code here
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends