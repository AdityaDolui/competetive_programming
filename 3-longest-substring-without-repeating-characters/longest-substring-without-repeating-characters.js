/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let l=0,h=0;
    let ans=0;
    let set=new Set();

         while(h<s.length){
            if(set.has(s.charAt(h))){
                while(true && set.size>0){
                    if(s.charAt(l)===s.charAt(h)){
                        l++;
                        break;}
                    set.delete(s.charAt(l));
                    l++;

                }
            }
            else set.add(s.charAt(h));
            ans=Math.max(ans,set.size);
            h++;
        }

        return ans;


};