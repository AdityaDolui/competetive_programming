class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
     
          vector<unordered_map<char,int>> arr2(words2.size());
          unordered_map<char,int> required ;
     
          for(int i=0;i<words2.size();i++){
             string str=words2[i];
            for(char ch: str){
                arr2[i][ch]++;
            }
          }

        for(auto it:arr2){
           
            for(auto val:it){
                required[val.first]=max(required[val.first],val.second);
              
            }
          
        }
           
         
         
        for(int i=0;i<words1.size();i++){

            unordered_map<char,int> map;
            for(auto ch:words1[i]){
                map[ch]++;
            }
            
            cout<<endl;
            bool flag=true;

            for(auto val:required){
                if( val.second > map[val.first]){
                    flag=false;
                    break;
                }
                
                 
            }
            if(flag){
                    cout<<i;
                    ans.push_back(words1[i]);
                    }
        }
        
          return ans;
    }
};