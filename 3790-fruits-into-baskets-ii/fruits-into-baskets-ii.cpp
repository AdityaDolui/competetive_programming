class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
 
        int cnt=0;
      
          for(int i=0;i<fruits.size();i++){
              
              for(int j=0;j<fruits.size();j++){
                  
              if(baskets[j]>=fruits[i]){
                  baskets[j]=INT_MIN;
                  cnt++;
                  break;
              }              
            }
        
        }
       
         return  fruits.size()-cnt;
    }
};