class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int cnt=0;
      //  vector<pair<int,int>> skills;
        deque<int> q;

        unordered_map<int,int> map;
        for(int i=0;i<skills.size();i++){map[skills[i]]=i;
        q.push_back(skills[i]);
        }
        int maxi=*max_element(skills.begin(),skills.end());
        if(k>=skills.size()){
            
            return map[maxi];
        }
        if(map[maxi]<=k)return map[maxi];
        int i=0;
        while(true){
            if(i>skills.size())return map[maxi];
           // if(skills.empty())break;
            if(cnt>=k)return map[q.front()] ;
            int first=q.front();
            q.pop_front();
            int second=q.front();
            q.pop_front();
            if(first<second){
                q.push_front(second);
                q.push_back(first);
                cnt=1;     
            }else{
                cnt++;
                 q.push_back(second);
                 q.push_front(first);
            }
            cout<<i<<" ";
            i++;
}
return -1;
    }
};