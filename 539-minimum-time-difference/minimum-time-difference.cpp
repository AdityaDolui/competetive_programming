class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
    vector<int> arr,arr2;
    for(auto it:timePoints){
        int val=(stoi(it.substr(0,2)))*60;
        val+=stoi(it.substr(3,2));
        arr.push_back(val);
        arr.push_back((val-(24*60)));

    }
    sort(arr.begin(),arr.end());
    int ans=INT_MAX;
    for(int i=1;i<arr.size();i++)ans=min(ans,(arr[i]-arr[i-1]));
        for(auto it:arr)cout<<it<<" ";
    return ans;
    }
};