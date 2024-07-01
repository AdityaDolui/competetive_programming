class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        if(n<3)return false;
        int cnt=0;
        int i=0,j=0;
        while(j<n){
            while(j-i>=3){
                if(arr[i]&1)cnt--;
                i++;
            }
            if(arr[j]&1)cnt++;
            if(cnt==3)return true;
            j++;
        }
        return false;
    }
};