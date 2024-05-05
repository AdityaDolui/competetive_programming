class Solution {
public:
    vector<int>  divis(int n){
        vector<int> ans;
        for(int i=1;i<=n/2;i++){
        if(n%i ==0){
            ans.push_back(i);
            
        }
            
            }
        
        return ans;
}
    int minAnagramLength(string s) {
        vector<int> div=divis(s.length());
      //  bool flag=true;
        
        for(auto it:div){
            unordered_map<char,int> map;
            
           bool flag=true;
            bool check=true;
            for(int i=0;i<=s.length()-it;i+=it){
                 unordered_map<char,int> map1;
                 
                for(int j=i;j<i+it;j++){
                    map1[s[j]]++;
                }
                if(flag){map=map1;
                flag=false;
                }
                else{
                    if(map!=map1){
                        check=false;
                        break;
                    }
                }
            }
            if(check)return it;
            
            
            
        }
        return s.length();
    }
};