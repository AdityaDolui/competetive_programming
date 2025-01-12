class Solution {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        
        List<String> ans=new ArrayList<>();
         List<HashMap<Character,Integer>> arr1=new ArrayList<>();
           List<HashMap< Character,Integer>> arr2=new ArrayList<>();
         HashMap<Character,Integer> required =new HashMap<>();
       

        for (String word : words1) {
            HashMap<Character, Integer> tempMap = new HashMap<>();
            for (char ch : word.toCharArray()) {
                tempMap.put(ch, tempMap.getOrDefault(ch, 0) + 1);
            }
            arr1.add(tempMap);
        }

        for (String word : words2) {
            HashMap<Character, Integer> tempMap = new HashMap<>();
            for (char ch : word.toCharArray()) {
                tempMap.put(ch, tempMap.getOrDefault(ch, 0) + 1);
            }
            arr2.add(tempMap);
        }

        for(int i=0;i<arr2.size();i++){
            HashMap<Character,Integer> map=new HashMap<>(arr2.get(i));

            map.forEach((key,value)->{
                 required.put(key,Math.max(required.getOrDefault(key,0),value));
            });
           
        }
          for (Map<Character, Integer> map : arr2) {
            for (Map.Entry<Character, Integer> entry : map.entrySet()) {
                required.put(entry.getKey(), Math.max(required.getOrDefault(entry.getKey(), 0), entry.getValue()));
            }
        }


    for(int i=0;i<words1.length;i++){
       // AtomicBoolean flag=new AtomicBoolean(true);

        HashMap<Character, Integer> map =new HashMap<>(arr1.get(i));

        // map.forEach((key,value)->{
        //     if(required.getOrDefault(key,0)>value){
        //         flag.set(false);
        //         return;
        //     }
        // });
        // if(flag.get()==true)ans.add(words1[i]);

                final boolean[] flag = {true};  // Use an array to modify the flag inside forEach

            required.forEach((key, value) -> {
                if (value > map.getOrDefault(key, 0)) {
                    flag[0] = false;  // Update the flag
                }
            });

            if (flag[0]) {
                ans.add(words1[i]);
            }

     }

        
        return ans;
    }
}