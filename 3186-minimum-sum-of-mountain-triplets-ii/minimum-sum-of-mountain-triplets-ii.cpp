
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
     vector<int> pre(n,1e9),post(n,1e9);
        pre[0]=1e9;
        pre[1]=nums[0];
        for(int i=2;i<n-1;i++){
            pre[i]=min(nums[i-1],pre[i-1]);
}
        post[n-2]=nums[n-1];
      for(int i=n-3;i>=0;i--){
          post[i]=min(post[i+1],nums[i+1]);
      }
     /*   for(auto it :pre)cout<<it<<" ";
        cout<<endl;
        for(auto it :post)cout<<it<<" ";
        cout<<endl;
        */
       int mini=1e9;
       for(int i=0;i<n-1;i++){
     //      cout<<i;
           if(nums[i]>pre[i] && nums[i]>post[i]){
        //       cout<<"yes";
            mini=min(mini,(nums[i]+pre[i]+post[i]));
           }
           
       }
  //     cout<<mini<<" ";
       if(mini==1e9)return -1;
       return mini;
        
    }
};