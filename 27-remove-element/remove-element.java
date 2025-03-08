class Solution {
    public int removeElement(int[] nums, int val) {
        
        int ans=0;
        int[] temp=new int[nums.length];
        int i=0;
        for(int element: nums){
           if(val!=element){
            ans++;
            temp[i++]=element;
           }
            }
            System.arraycopy(temp,0,nums,0,temp.length);
        return ans;
    }
}