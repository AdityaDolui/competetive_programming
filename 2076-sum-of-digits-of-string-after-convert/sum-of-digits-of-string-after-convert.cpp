class Solution {
public:
    int getLucky(string s, int k) {
        string str="";
        for(auto ch:s){
            str+=to_string(ch-'a'+1);
        }
       
        while(k--){
           
            int sum=0;
            for(auto ch:str){

                sum+=ch-'0';
            }
            str=to_string(sum);
        }
        
        return stoi(str);
    }
};