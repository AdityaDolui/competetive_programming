class Solution {
public:
     bool check(string first,string second){
       int i=0;
        int cnt=0;
       
        unordered_map<char,int> s;
        vector<bool> f(8,0);
      
        while(i<first.length()){
            if(first[i]!=second[i]){
                f[i]=true;
                s[second[i]]++;
            }
            i++;
        }
   
       for(int i=0;i<8;i++){
        if(f[i]){
            char ch=first[i];
            if(s[ch]<=0)return false;
            s[ch]--;
            cnt++;
            if(cnt>2)return false;
        }
       }
       if(!cnt || cnt==2)return true;
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