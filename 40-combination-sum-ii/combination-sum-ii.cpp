class Solution {
public:
 void f(vector<int> &A,vector<vector<int>> & res, vector<int> & curr ,int i, int target){

     if(target==0){
           
           
            res.push_back(curr);
            
            return;
        }

        if( target<0)return;
        
        

        
         

         for(int index=i;index<A.size();index++){

         if(index>i && A[index]==A[index-1])continue;
        curr.push_back(A[index]);

        f(A,res,curr,index+1,target-A[index]);
        
        curr.pop_back();
        
         }
         
        
    }
    vector<vector<int>> combinationSum2(vector<int>& A, int B) {
         sort(A.begin(),A.end());
        //A.erase(unique(A.begin(),A.end()),A.end());
         vector<vector<int> > res;
         vector<int> curr;
         
         f(A,res,curr,0,B);
       
        
      
          return res;
    }
};