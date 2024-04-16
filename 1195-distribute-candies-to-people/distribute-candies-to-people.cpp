class Solution {
public:
    vector<int> distributeCandies(int N, int K) {
         vector<int> ans(K);
        int i=0;
        int candy=1;
        while(N){
            if(candy>N){
                ans[i%K]+=N;
                break;
            }
            
            ans[i%K]+=candy;
            N-=candy;
            candy++;
            i++;
           
           
          
        }
        return ans;
    }
};