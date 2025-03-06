class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        // int k=0,i=0;
        // while(k<n && i<m ){
        //     if(nums2[k]>=nums1[i])i++;
           
        //     else{
        //         int temp=nums1[i];
        //         nums1[i]=nums2[k];
        //         nums2[k]=temp;
        //         k++;
               
        //     }
            
        // }
        // System.out.print(i+" "+k+" "+Arrays.toString(nums2));
        // k=0;
        // while(i<(m+n) && k<n){
        //     nums1[i]=nums2[k];
        //     i++;
        //     k++;
        // }
        int [] ans=new int[(m+n)];
        int i=0,j=0,k=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                ans[k++]=nums1[i++];
            }else{
                ans[k++]=nums2[j++];
            }
        }

        while(i<m){
            ans[k++]=nums1[i++];
        }
         while(j<n){
             ans[k++]=nums2[j++];
        }
        //nums1=Arrays.copyOf(ans);
         System.arraycopy(ans, 0, nums1, 0, m + n);
    }
}