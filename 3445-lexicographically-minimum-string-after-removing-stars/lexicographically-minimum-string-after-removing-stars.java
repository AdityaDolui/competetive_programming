class Solution {
    public String clearStars(String s) {
        
        PriorityQueue<Character> pq=new PriorityQueue<>();
        Map<Character,Deque<Integer>> map=new HashMap<>();
        StringBuilder str =new StringBuilder();
        boolean[] validate=new boolean[s.length()];
        Arrays.fill(validate,true);
        int i=0;
        for(char ch: s.toCharArray()){
            if(ch=='*'){
                char smallest=pq.peek();
                pq.poll();
                validate[i]=false;
                validate[  map.get(smallest).removeLast()]=false;
              
            }else{
                pq.add(ch);
                map.putIfAbsent(ch,new ArrayDeque<>());
                map.get(ch).add(i);
            }
            i++;
        }

        for(  i=0;i<s.length();i++){
            if(validate[i]==true)str.append(s.charAt(i));
        }
        return str.toString();
    }
}