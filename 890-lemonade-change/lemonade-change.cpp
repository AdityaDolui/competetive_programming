class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> arr(3,0);
        for(auto it:bills){
            if(it==5)arr[0]++;
            else if(it==10){
                 
                if(arr[0]<=0) return false;
                arr[0]--;
                arr[1]++;
                
            }
            else{
                if((arr[1]>0 && arr[0]>0) || (arr[0]>=3)){
                    if(arr[1]>0 && arr[0]>0){
                    arr[1]--;
                    arr[0]--;
                }
                else{
                    arr[0]-=3;
                }
                arr[2]++;
                }else return false;
            }
        }
        return true;
    }
};