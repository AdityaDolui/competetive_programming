class Solution {
public:
int binary( vector<int> & arr,int tar){
    int l=0,r=arr.size()-1;
    int res=-1;

    while(l<=r){
        int mid=l+(r-l)/2;

        if(arr[mid]<=tar){
            res=arr[mid];
            l=mid+1;
        }else r=mid-1;

       
    }
     return res;
}

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<pair<int,int>>  candle;
        

        int cnt=0;
        vector<int> cnd;

        for(int i=0;i<s.size();i++){
            if(s[i]=='|'){
                cnd.push_back(i);
            candle.push_back({i,cnt});
            }
            else cnt++;
        }

        unordered_map<int,int> map;
        for(auto it:candle)map[it.first]=it.second;
        //for(auto it: candle)cout<<it.first<<" "<<it.second<<endl;

        vector<int> ans;
       
        for(auto it:queries){
            auto iit=lower_bound(cnd.begin(),cnd.end(),it[0]);
            if(iit==cnd.end()){
                ans.push_back(0);
            continue;}
            int num=iit-cnd.begin();
            
            

            int num2=binary(cnd,it[1]);
            cout<<num2<<" "<<cnd[num]<<endl;
            if(num==candle.size() || num2==-1|| cnd[num]>=num2)ans.push_back(0);
            else ans.push_back(map[num2]-map[cnd[num]]);

        }

        return ans;

    }
};