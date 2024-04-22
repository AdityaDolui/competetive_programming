class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<int> setL, setU;
        vector<int> ans(26,false);
        vector<int> notDone(26,true);
        for(auto it:word){
            if(it>=97){
                if(setU.find(it)!=setU.end()){
                    ans[it-'a']=true;
                    notDone[it-'a']=false;
}
                setL.insert(it);
                
}
            else{
                 if(setL.find(it+32)!=setL.end()){
                    ans[it-'A']=true;
}
                setU.insert(it+32);
                
}
        }
        int cnt=0;
       for(int i=0;i<26;i++){
           if(ans[i] && notDone[i])cnt++;
       }
        
        return cnt;
    }
};