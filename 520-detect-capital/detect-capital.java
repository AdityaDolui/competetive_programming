class Solution {
    public boolean detectCapitalUse(String word) {
      boolean a= word.chars()
                .mapToObj(ch-> (char)ch)
                .allMatch(ch->Character.isUpperCase(ch));

        boolean b=word.chars()
                .mapToObj(ch-> (char)ch)
                .allMatch(ch->Character.isLowerCase(ch));
        boolean c= Character.isUpperCase(word.charAt(0)) 
                    && word.substring(1).chars()
                                        .mapToObj(ch->(char)ch)
                                        .allMatch(Character::isLowerCase);

        return (a || b || c);
    }
}