class Solution {
public:
    int passThePillow(int n, int time) {
        int rem=time%(n-1);
        int div=time/(n-1);

        if(div&1)return n-(rem);
        return rem+1;

     }
};