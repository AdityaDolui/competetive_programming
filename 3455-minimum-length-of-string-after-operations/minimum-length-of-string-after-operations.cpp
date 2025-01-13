class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> map;
        for(auto ch:s){
            map[ch]++;
        }
        int k=0;
        for(auto it:map){
            if(it.second%2==0){
                k+=2;
            }else{
                k++;
            }
        }
        return k;
    }
};