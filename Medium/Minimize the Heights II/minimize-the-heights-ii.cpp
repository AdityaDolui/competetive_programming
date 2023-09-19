//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
           int st=0,en=n-1;
        
        sort(arr,arr+n);
        int ans=arr[en]-arr[st];
       for(int i=1;i<n;i++){
           int currmin=min(arr[0]+k,arr[i]-k);
           int currmax=max(arr[i-1]+k,arr[n-1]-k);
           if(currmin<0)continue;
           ans=min(ans,(currmax-currmin));
       }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends