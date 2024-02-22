class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
     vector<int> pref(n,0);
     pref[0]=nums[0];

     unordered_map<int,int> map;
     map[pref[0]]=0;
     for(int i=1;i<n;i++){
         pref[i]=pref[i-1]+nums[i];
         map[pref[i]]=i;
     }
     map[0]=-1;
    int ans=INT_MAX;
     int num=0;
     int k=n-1;
     while(k>=0){
         if(map.find(x-num)!=map.end()){
             cout<<map[x-num]<<" "<<(x-num);

          //   if(map[x-num]<k)
            ans=min(ans, (n-k+map[x-num]));
         }
         num+=nums[k];
         k--;
     }
     if(ans>n)
    return -1;

    else return ans;
    }
};