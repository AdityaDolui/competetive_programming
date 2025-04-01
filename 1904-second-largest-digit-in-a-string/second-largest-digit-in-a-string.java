class Solution {
    public int secondHighest(String s) {
        return s.chars()     
                    .filter(ch-> Character.isDigit(ch))
                    .map(ch->ch-'0')
                    .boxed()
                    .distinct()
                    .sorted((a,b)->b-a)
                    .skip(1)
                    .findFirst()
                    .orElse(-1);

    
    }
}