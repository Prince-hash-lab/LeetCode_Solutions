// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> quadraticRoots(int a, int b, int c) {
        // code here
        float d=b*b-(4*a*c);
        vector<int> ans;
        if(d<0) { ans.push_back(-1); return ans; }
        float num1=floor((-b+(float)sqrt(d))/(2*a));
        float num2=floor((-b-(float)sqrt(d))/(2*a));
        ans.push_back(max(num1, num2));
        ans.push_back(min(num1, num2));
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        Solution ob;
        vector<int> roots = ob.quadraticRoots(a, b, c);
        if (roots.size() == 1 && roots[0] == -1)
            cout << "Imaginary";
        else
            for (int i = 0; i < roots.size(); i++) cout << roots[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends