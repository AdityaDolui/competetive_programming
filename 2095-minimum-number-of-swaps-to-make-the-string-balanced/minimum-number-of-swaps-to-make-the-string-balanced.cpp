class Solution {
public:
    int minSwaps(string s) {
        int first =0, swap=0;

        for(auto it:s){
            if(it==']'){
                if(first==0){
                    swap++;
                    first++;
                }else{
                    first--;
                }
            }else{
                first++;
            }
        }
        return swap;
    }
};