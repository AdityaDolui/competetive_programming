class Solution {
    public int maximumSetSize(int[] nums1, int[] nums2) {
         List<Integer> list1 = Arrays.stream(nums1).boxed().collect(Collectors.toList());
        List<Integer> list2 = Arrays.stream(nums2).boxed().collect(Collectors.toList());
        Set<Integer> set1=new HashSet<>(list1);
          Set<Integer> set2=new HashSet<>(list2);
       

        Set<Integer> set3 =new HashSet<>();
        set3.addAll(set1);
        set3.retainAll(set2);

       int ans=0;
       int a=set1.size(),b=set2.size(),c=set3.size();
       int val1=Math.min(list1.size()/2,a-c);
       ans+=val1;
       int val2=Math.min(list2.size()/2,(b-c));
       ans+=val2;

    ans+=Math.min((list1.size()/2-val1)+(list2.size()/2-val2),c);
    return ans;

    }
}