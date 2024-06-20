class Solution {
public:
bool check(vector<int>& position, int m,int ans){
    int prev=position[0];
    m--;
    for(int i=1;i<position.size();i++){
     if(position[i]-prev>=ans){
        m--;
        prev=position[i];
}
if(!m)return true;
    }
return false;
}
    int maxDistance(vector<int>& position, int m) {
            sort(position.begin(),position.end());
        //int mini=*min_element(position.begin(),position.end());
         // int maxi=*max_element(position.begin(),position.end());
          int h= 1e9; //(maxi-mini);
          int l=0;
          int ans=0;
          while(l<=h){
            int mid=(l+h)>>1;
            if(check(position,m,mid)){
                ans=mid;
                l=mid+1;
            }else h=mid-1;
          }
          return ans;
    }
};