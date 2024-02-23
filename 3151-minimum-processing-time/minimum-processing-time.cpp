class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.begin(),tasks.end(),greater<int>());
       // for(auto it: tasks)cout<<it<<" ";
        sort(processorTime.begin(),processorTime.end());
        int ans=0;
        for(int i=0;i<tasks.size();i++){
            int num=i/4;
            ans=max(ans,processorTime[num]+tasks[i]);
        }
        return ans;
    }
};