class Solution {
    public int findValue( int val,List<Integer> nums){
        int left=0,right=nums.size()-1;
        while(left<=right){
        int mid=left+(right-left)/2;

        if(nums.get(mid)==val)return mid;
        if(nums.get(mid)<val)left=mid+1;
        else right=mid-1;
        }
        return -1;
    }
    public List<Integer> solveQueries(int[] nums, int[] queries) {
        Map<Integer,List<Integer>> map=new TreeMap<>();
        for(int i=0;i<nums.length;i++){
      //  //    map.put(nums[i],map.getOrDefault(nums[i],new ArrayList<>()).add(i));
        List<Integer> list=map.getOrDefault(nums[i],new ArrayList<>());
        list.add(i);
        map.put(nums[i],list);
        }

        List<Integer> ans=new ArrayList<>();

        for(int i=0;i<queries.length;i++){
            int tar=nums[queries[i]];
            List<Integer> list=map.get(tar);
            if(list.size()==1){
                ans.add(-1);
               //continue;
            }else{
            int pos=findValue(queries[i],list);
            // System.out.println(pos+" "+i);

          //  int rightValue=Math.abs(list.get((pos+1)%list.size())-list.get(pos));
            int rightValue;
            if(pos==list.size()-1){
                 rightValue=nums.length-list.get(pos)+list.get((pos+1)%list.size());
            }else{
                 rightValue=list.get(pos+1)-list.get(pos);
            }
           
            int l;
            int leftValue;
            if(pos==0){
                l=list.size()-1;
                leftValue=list.get(pos)+(nums.length-list.get(l));
            }else{
                l=pos-1;
                leftValue=list.get(pos)-list.get(l);
            }
     
            ans.add(Math.min(leftValue,rightValue));
            }
        }
        
      
       return ans;
}
}