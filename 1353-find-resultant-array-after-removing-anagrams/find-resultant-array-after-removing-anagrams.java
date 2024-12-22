class Solution {
    public List<String> removeAnagrams(String[] words) {
        
        HashMap<String,Integer> map=new HashMap<>();
        List<String> ans=new ArrayList<>();
        int i=0;
        for(String str:words){
            char[] charArray=str.toCharArray();
            Arrays.sort(charArray);
            String newStr=new String(charArray);
            if(!map.containsKey(newStr)){
                map.put(newStr,i);
                ans.add(str);
            }else{
                if(map.get(newStr)!=i-1){
                    
                    ans.add(str);
                }
                map.put(newStr,i);
            }
            i++;
        }
        return ans;

    }
}