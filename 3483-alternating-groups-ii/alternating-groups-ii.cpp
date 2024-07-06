class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            if(i==0){
                if(colors[0]!=colors[n-1])arr[0]=1;
            }
            else{
                if(colors[i]!=colors[i-1])arr[i]=arr[i-1]+1;
                else arr[i]=arr[i-1];
            }
        }
        int ans=0;
        
        for(int i=0;i<n;i++){
            int l=i+k-1;
            
            int first=arr[i];
            int cal=0;
            if(l>=n){
                cal=arr[n-1];
                l=l%n;
                
            }
             cal+=arr[l];
            if(cal-first==k-1)ans++;
            
            
            
        }
        return ans;
    }
};