class Solution {
public:
    int minNumberOfFrogs(string crk) {
        int n=crk.length();
     
     if(n%5!=0 && crk[0]!='c')return -1;
     int ans=0;
     unordered_map<char,int> map;
     for(auto it: crk){
         if(it=='r' && map['c']<=map[it])return -1;
         else if(it=='o' && map['r']<=map[it])return -1;
         else if(it=='a' && map['o']<=map[it])return -1;
         else if(it=='k')  {
             if(map['a']<=map[it])return-1;
             for(auto &ii:map)ii.second--;
             }
             map[it]++;

        ans=max(ans,map['c']);
     }
     for(auto it: map)if(it.second)return -1;
     return ans;
    }
};