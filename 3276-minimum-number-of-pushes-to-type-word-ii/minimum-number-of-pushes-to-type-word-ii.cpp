class Solution {
public:
    int minimumPushes(string word) {
        vector<int> arr(26,0);
        for(auto it:word){
            arr[it-'a']++;
        }
        sort(arr.begin(),arr.end(),greater<int>());

        int k=8;
        int i=0;
        int ans=0;
        int div=0;
        while(i<26){
            div=k/8;
            ans+=arr[i]*div;
            i++;
            k++;
        }
        return ans;
    }
};