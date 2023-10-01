//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

//User function Template for C++

class Solution{
    public:
    int closest3Sum(int nums[], int n, int target)
    {
         sort(nums , nums+n); 
         
        int mini=INT_MAX;
        int ans;
       
        for(int i=0;i<n;i++){
            
                int first=nums[i];
                int target1=target-first;
                int j=i+1,k=n-1;
                while(j<k){
                    if((nums[j]+nums[k])<target1){
                        int diff=abs(target1-(nums[j]+nums[k]));
                        if(diff<mini){
                            mini=diff;
                        ans=nums[i]+nums[j]+nums[k];
                        }

                        j++;
                    } 
                    else if((nums[j]+nums[k])>target1){
                        int diff=abs(target1-(nums[j]+nums[k]));
                        if(diff<mini){
                            mini=diff;
                        ans=nums[i]+nums[j]+nums[k];
                        }

                    k--;
                    }
                    else {
                        return nums[i]+nums[j]+nums[k];;
                                            }
                }
                while(i+1<n && nums[i]==nums[i+1])i++;
        }
        
        return ans;

    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends