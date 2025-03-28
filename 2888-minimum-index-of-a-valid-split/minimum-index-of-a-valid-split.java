class Solution {
    public int minimumIndex(List<Integer> nums) {
        int val=nums.get(0);
        int cnt=1;
        for(int i=0;i<nums.size();i++){
         if(cnt==0)val=nums.get(i);
         cnt+=val==nums.get(i)?1:-1;
        }
        int check=Collections.frequency(nums,val);
        if(check<=nums.size()/2)return -1;

        cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums.get(i)==val)cnt++;
            if(cnt>((i+1)/2) && ((check-cnt)>(nums.size()-i-1)/2))return i;
        }
        return -1;
    }
}