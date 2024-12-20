class Solution {
    public int maxChunksToSorted(int[] arr) {
        Stack<Integer> st=new Stack();
        int n=arr.length;
        // for(int i=n-1;i>=0;i--){
        //     while(!st.isEmpty() && st.peek()<arr[i])st.pop();

        //     st.push(arr[i]);
        // }
        int max=0,count=0;
         for(int i=0;i<n;i++){
           max=Math.max(arr[i],max);
           if(max==i)count++;
        }
    return count;
    }
}