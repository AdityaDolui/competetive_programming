class Solution {
    public String capitalizeTitle(String title) {
        return Arrays.stream(title.split(" "))
                .map(str->str.toLowerCase())
                .map(str-> str.length()>2 ? Character.toUpperCase(str.charAt(0))+str.substring(1):str )
                .collect(Collectors.joining(" "));
                    
    }
}