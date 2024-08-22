class Solution {
public:
    int findComplement(int num) {
        
        string str=bitset<32> (num).to_string();
        auto it=str.find('1');
        string str2;
        str2=str.substr(it);
        for(int i=0;i<str2.size();i++){
            if(str2[i]=='1')str2[i]='0';
            else str2[i]='01';
        }
      
        return stoi(str2,nullptr,2);
    }
};