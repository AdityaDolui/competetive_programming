class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> map,map2;
        for(auto it:s1){
            map[it]++;
        }
        int k=0;
        int l=0,h=0;
       // map2[s2[0]]++;
        while(h<s2.length()){
            map2[s2[h]]++;
            k++;
            h++;
            
            while(k>s1.length()){
                map2[s2[l]]--;
                if(map2[s2[l]]==0)map2.erase(s2[l]);
                l++;
                k--;
            }
            if(map2==map)return true;
        //      for(auto it:map2){
        //     cout<<it.first<<" "<<it.second<<" || ";
            
        // }
        // cout<<"**";
         }
       
        return false;
    }
};