class Solution {
public:
bool check(int M,int K,vector<int> arr,int  ans){
      
      int flower=0;
      int buq=0;
      for(int i=0;i<arr.size();i++){
          if(arr[i]<=ans){
               flower++;
              if(flower==K){
                  buq++;
                 flower=0;
                
              }
             
          }
          else flower=0;
      }
       if(buq>=M)return true;
      return false;
  }
    int minDays(vector<int>& bloomDay, int M, int K) {
        //if(M*K > bloomDay.size())return -1;
      int  l=0;
      int ans=-1;
      int h=*max_element(bloomDay.begin(),bloomDay.end());
     
      while(l<=h){
          int mid=(l+h)>>1;
          if(check(M,K,bloomDay,mid)){
              ans=mid;
              h=mid-1;
          }
          else l=mid+1;
      }
      return ans;
    }
};