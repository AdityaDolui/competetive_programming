class Solution {
    public int numRabbits(int[] answers) {
       return Arrays.stream(answers)
                        .boxed()
                        .collect(Collectors.groupingBy(s->s,Collectors.counting()))
                        .entrySet()
                        .stream()
                        .map(s->{
                            int val=s.getKey()+1;
                            int div=(int)(s.getValue()/val);
                            div+=(s.getValue()%val)!=0 ?1:0;
                            return val*div;
                        })
                        .mapToInt(Integer::intValue)
                        .sum();
  
          
    }
}