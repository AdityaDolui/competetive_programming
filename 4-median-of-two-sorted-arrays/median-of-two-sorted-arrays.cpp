class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        
        int m=arr1.size();
       int n=arr2.size();
       
       if(n<m)return findMedianSortedArrays(arr2,arr1);
       
       int l=0,h=m;
       while(l<=h){
           int cut1=(l+h)>>1;
           int cut2=(n+m+1)/2-cut1;
           
           int left1=cut1==0? INT_MIN:arr1[cut1-1];
           int left2=cut2==0? INT_MIN:arr2[cut2-1];
           int right1=cut1==m? INT_MAX:arr1[cut1];
           int right2=cut2==n? INT_MAX:arr2[cut2];
           
           if(left1<=right2 && left2<=right1){
               if((n+m)%2==0) return (max(left1,left2)+min(right1,right2))/2.0;
               else return max(left1,left2);
           }
           else if(left1>right2){
               h=cut1-1;
           }
           else l=cut1+1;
       }
       return 0.0;
    }
};