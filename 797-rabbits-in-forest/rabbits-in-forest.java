class Solution {
    public int numRabbits(int[] answers) {
        int sum= Arrays.stream(answers)
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
    return sum;
            // return sum + (int) Arrays.stream(answers)
            //             .boxed()
            //             .collect(Collectors.groupingBy(s->s, Collectors.counting()))
            //             .entrySet()
            //             .stream()
            //             .filter(s-> s.getKey()==0)
            //             .map(s->s.getValue())
            //             .mapToLong(Long::longValue)
            //             .sum();
    }
}