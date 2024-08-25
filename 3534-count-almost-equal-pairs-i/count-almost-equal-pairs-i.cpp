class Solution {
public:
     bool check(string first,string second){
        int i=0,j=0;
        
        bool flag=0;
        int fnon=-1,snon=-1;
     
        while(i<first.length()){
            if(first[i]!=second[i]){
                if(flag){
                    if(second[i]==fnon && first[i]==snon){
                        fnon=-1;
                        snon=-1;
                    }
                    else{
                        return false;
                    }
                }else{
                    flag=1;
                    fnon=first[i];
                    snon=second[i];
                }
            }
           
            i++;
        }
        if(fnon==-1) return true;
        return false;
       
    }
    string constructs(string str,int val){
        string s="";
        while(val--){
            s+='0';
        }
        s+=str;
        return s;
    }
    int countPairs(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                string first=to_string(nums[i]),
                second=to_string(nums[j]);
                if(first.length()!=second.length()){
                    if(first.length()<second.length()){
                        first=constructs(first,second.length()-first.length());
                    }else{
                        second=constructs(second,first.length()-second.length());
                    }
                }
                
                if(check(first,second)){ans++;
                                      
                                       }
                
            }
        }
        return ans;
    }
};