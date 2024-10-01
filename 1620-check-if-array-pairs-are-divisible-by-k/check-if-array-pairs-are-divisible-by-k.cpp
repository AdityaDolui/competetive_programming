class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> map;
        int cnt=0;
        for(auto it:arr){
            it=((it%k)+k)%k;
            if(it%k==0){
                if(map[0]>0){
                    map[0]--;
                    cnt++;
                }
               else map[0]++;
            }
            else{

             if(map[k-(it%k)]>0){
                map[k-(it%k)]--;
                cnt++;
             }else map[it%k]++;

            }
        }
        return (arr.size()/2==cnt);
    }
};