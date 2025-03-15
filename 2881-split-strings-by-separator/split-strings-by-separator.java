class Solution {
    public List<String> splitWordsBySeparator(List<String> words, char separator) {

       List<String> list=new ArrayList<>();
       for(String str:words){
        String[] arr=str.split("["+separator+"]");
        for(String s:arr){
            if(!s.trim().isEmpty()){
                list.add(s);
            }
        }
       }
       return list;

    }
}